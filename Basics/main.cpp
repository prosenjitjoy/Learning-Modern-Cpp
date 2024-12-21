#include <cstdlib>
#include <iostream>
#include <print>
#include <type_traits>
#include <unordered_map>

void foo() {
    std::println("Risky foo");
}

struct Point {
    float x;
    float y;
};

struct BeforeMain {
    BeforeMain() {
        std::println("Constructiting before main");
    }
    void test() {
        std::println("test function");
    }
};

BeforeMain b;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return (b == 0) ? 0 : a / b;
}

void print_number(int num) {
    if (num > 100) {
        return;
    }

    std::print("{} ", num);
    print_number(num + 1);
}

struct Product {
    std::string name;
    double price;
    int rating;
    bool available;
};

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::println("No argument passed!");
    } else {
        for (int i = 1; i < argc; i++) {
            std::println("{}", argv[i]);
        }
    }

    print_number(1);
    std::println();

    std::println("{}", std::is_fundamental_v<Point>);
    std::println("{}", std::is_compound_v<Point>);
    std::println("{}", std::is_compound_v<char>);
    std::println("{}", std::is_compound_v<std::string>);

    int ivar{26};
    char ch = 't';
    double d = 3.14;
    int* ptr = &ivar;
    char* pch = &ch;
    double* pd = &d;

    std::println("{}: {}", sizeof(ptr), *ptr);
    std::println("{}: {}", sizeof(pch), *pch);
    std::println("{}: {}", sizeof(pd), *pd);

    auto p = static_cast<Point*>(std::malloc(sizeof(Point)));
    Point* p1 = new Point;
    delete p1;
    std::println("{}", sizeof(p));
    p->x = 1.2;
    p->y = 1.4;
    std::println("{}: {}", p->x, p->y);
    free(p);

    // divide(5, 0);

    void (*fp)() = &foo;
    fp();

    std::unordered_map<char, int (*)(int, int)> operations;
    operations['+'] = &add;
    operations['-'] = &subtract;
    operations['*'] = &multiply;
    operations['/'] = &divide;

    // char op;
    // int num1, num2;
    // std::print("Enter num1: ");
    // std::cin >> num1;
    // std::print("Operations(+,-,*,/): ");
    // std::cin >> op;
    // std::print("Enter num2: ");
    // std::cin >> num2;

    // std::println("Result: {}", operations[op](num1, num2));

    std::println("{}", sizeof(Product));

    return 0;
}
