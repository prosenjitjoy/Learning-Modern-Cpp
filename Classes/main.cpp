#include <print>
#include <string>

#include "Product.h"
#include "Warehouse.h"
#include "inheritance.h"
#include "money.h"
#include "polymorphism.h"

struct Product {
    std::string name;
    double price;
    int rating;
    bool available;
};

void initialize(Product* p) {
    p->name = "";
    p->price = 0.0;
    p->rating = 0;
    p->available = false;
}

void set_name(Product* p, const std::string& name) {
    p->name = name;
}

std::string get_name(Product* p) {
    return p->name;
}

void set_price(Product* p, double price) {
    if (price >= 0 || price <= 9999) {
        p->price = price;
    }
}

double get_price(Product* p) {
    return p->price;
}

void set_rating(Product* p, int r) {
    if (r >= 1 && r <= 5) {
        p->rating = r;
    }
}

int get_rating(Product* p) {
    return p->rating;
}

struct Empty {};

struct Warehouse {
    Product* products;
    int capacity;
    int size;
};

void initialize_warehouse(Warehouse* w) {
    w->capacity = 1000;
    w->size = 0;
    w->products = new Product[w->capacity];
    for (int i = 0; i < w->capacity; i++) {
        initialize(&w->products[i]);  // initialize each Product object
    }
}

ProductClass create_apple() {
    ProductClass apple;
    apple.set_name("Red apple");
    apple.set_price(0.2);
    apple.set_rating(5);
    apple.set_availability(true);
    return apple;
}

int get_it() {
    int it{42};
    return it;
}

int main() {
    std::println("Hello World!");
    // Rectangle rect{2, 3};
    // std::println("{}", rect.perimeter());

    Product cpp_book;
    cpp_book.available = true;
    cpp_book.rating = 5;
    set_rating(&cpp_book, -12);
    std::println("{}", cpp_book.rating);

    Empty e;
    std::println("{}", sizeof(e));

    // mimicking a class
    initialize(&cpp_book);
    set_name(&cpp_book, "Mastering C++ Programming");
    std::println("Book title is: {}", get_name(&cpp_book));

    ProductClass red_apple = create_apple();
    ProductClass book;
    ProductClass* ptr = &book;
    ptr->set_name("Alice in Wonderland");
    ptr->set_price(6.8);
    std::println("I'm reading {} and I bought an apple for {}", book.name(),
                 red_apple.price());

    // int& impossible = get_it(); // compile error
    int&& possible{get_it()};

    Money m1{2};
    Money m2{4};
    std::println("{}", m1 != m2);

    Rectangle rect;
    rect.set_width(2);
    rect.set_height(4);
    std::println("{}", rect.area());

    Square sq{3};
    std::println("{}", sq.area());

    // Musician armstrong;
    Guitarist steve;
    Musician* m = nullptr;
    // m->play();
    m = &steve;
    m->play();

    return 0;
}
