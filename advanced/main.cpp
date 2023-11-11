#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <thread>
#include <mutex>
#include <vector>
#include <array>
#include <filesystem>
#include <chrono>
#include <string_view>
#include <any>
#include <variant>
#include <concepts>
#include <ranges>
#include <algorithm>
#include <span>
#include <numbers>

// mutex
std::mutex m; // will guard std::cout

// thread
void function1() {
    for (int i=0; i<5; i++) {
        std::lock_guard<std::mutex> lg(m);
        std::cout << "Executing function.\n";
    } // lock_guard goes out of scope here and unlocks the mutex
}

void function2(const std::string& param) {
    for (int i=0; i<5; i++) {
        m.lock();
        std::cout << "Executing function1." << param << "\n";
        m.unlock();
    }
}

// type aliases
using MyInt = int;
using MyString = std::string;
using MyVector = std::vector<int>;

// default constructor when using only copy constructor
class MyClass {
public:
    MyClass() = default; // defaulted member function
    MyClass(const MyClass& rhs) {
        std::cout << "Copy constructor invoked.\n";
    }
    MyClass& operator=(const MyClass& rhs) = delete; // delete the copy assignment operator
};

// auto for functions
auto myintfn() {
    return 123; // integer
}

auto mydoublefn() {
    return 3.14; // double
}

// union
union MyUnion {
    char c; // one byte
    int x; // four bytes
    double d; // eight bytes
};

// concepts
template <typename T>
concept MustBeIncrementable = requires (T x) {x++;};

template <typename T>
concept SupportsModule = requires (T x) {x%2;};

template<typename T> requires MustBeIncrementable<T> && SupportsModule<T>
void myfunction(T x) {
    std::cout << "The value conforms to both conditions: " << x << "\n";
}

// to hava .empty() and result of that should be convertible to type bool
template <typename T>
concept HasMemberFunction = requires (T x) {
    {x.empty()} -> std::convertible_to<bool>;
};

// likely unlikely - switch
void mychoice(int i) {
    switch(i) {
    [[likely]] case 1:
        std::cout << "Likely to be executed.\n";
        break;
    [[unlikely]] case 2:
        std::cout << "Unlikely to be executed.\n";
        break;
    default:
        break;
    }
}

// #warning
#warning "User-defined warning message."
#warning "Some diagnostics message."


int main()
{
    // unordered set
    std::unordered_set<int> myunorderedset = {1,2,5,-4,7,10};
    myunorderedset.insert(6); // insert a single value
    myunorderedset.insert({8,15,20, 1}); // insert multiple values
    myunorderedset.erase(-4);
    for (auto el: myunorderedset) {
        std::cout << el << "\n";
    }

    // unordered map
    std::unordered_map<char, int> myunorderedmap = {{'a',1}, {'b',2}, {'c',5}};
    myunorderedmap.insert({'d', 10});
    myunorderedmap['e'] = 4;
    for (auto el: myunorderedmap) {
        std::cout << el.first << ": " << el.second << "\n";
    }

    // tuple
    std::tuple<char,int,double> mytuple = {'a', 123, 3.14};
    std::cout << "The first element is: " << std::get<2>(mytuple) << "\n";

    auto mytuple1 = std::make_tuple<int,double,std::string>(123,3.14,"Hello World");
    std::cout << "The first tuple element is: " << std::get<0>(mytuple1) << "\n";
    std::cout << "The second tuple element is: " << std::get<1>(mytuple1) << "\n";
    std::cout << "The third tuple element is: " << std::get<2>(mytuple1) << "\n";

    // static_assert
    constexpr int x = 123;
    static_assert(x == 123, "The constexpr value is not 456.");

    // thread
    std::thread t1 {function1 }; // create and start a thread
    std::thread t2 {function2, "Hello World from a thread."};
    t1.join();  // wait for the t1 thread to finish
    t2.join(); // wait for the t2 thread to finish
    std::cout << "Continuing main...\n";

    std::thread t3 {function2, "Thread 1"};
    std::thread t4 {function2, "Thread 2"};
    t3.join();
    t4.join();

    // default constructor
    MyClass o; // Now OK
    MyClass o1 = o;
    MyClass o2;
    //    o2 = o;

    //  type aliases
    MyInt mi = 123;
    MyString s = "Hello World";
    MyVector v = {1,2,3,4,5};

    // literals
    int a = 10;
    int b = 0xA;
    int c = 012;
    int d = 0b1010;
    int e = 100'000'000;

    // auto for functions
    auto f = myintfn(); // int
    auto g = mydoublefn(); // double

    // constexpr lambdas
    constexpr auto mylambda = [](int x, int y) {return x+y;};
    static_assert(mylambda(10,20) == 30, "The lambda condition is not true.");

    // structured bindings
    std::array<int,3> arr = {1,2,3};
    auto [myvar1, myvar2, myvar3] = arr;
    std::cout << myvar1 << "\n";
    std::cout << myvar2 << "\n";
    std::cout << myvar3 << "\n";

    // structured bindings of reference
    auto& [var1, var2, var3] = arr;
    var1 = 10;
    var2 = 20;
    var3 = 30;
    for (auto el: arr) {
        std::cout << el << "\n";
    }

    // filesystem - check folder
    std::filesystem::path folderpath = "/home/joy/.zig";
    if (std::filesystem::exists(folderpath)) {
        std::cout << "The path: " << folderpath << " exists.\n";
    } else {
        std::cout << "The path: " << folderpath << " does not exists.\n";
    }

    // filesystem - check file
    std::filesystem::path filepath = "/home/joy/.bun/bin/bun";
    if (std::filesystem::exists(filepath)) {
        std::cout << "The file: " << filepath << " exists.\n";
    } else {
        std::cout << "The file: " << filepath << " does not exists.\n";
    }

    // filesystem - iterate over folder elements
    std::filesystem::path homepath = "/home/joy";
    for (auto el: std::filesystem::directory_iterator(homepath)) {
        std::cout << el.path() << "\n";
    }

    // filesystem iterate over folder elements recursively
    //    for (auto el: std::filesystem::recursive_directory_iterator(homepath)) {
    //        std::cout << el.path() << "\n";
    //    }

    // filesystem - create directory
    std::filesystem::path tempfolder = "/home/joy/tempfolder";
    std::filesystem::create_directory(tempfolder);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // filesystem - delete directory
    std::filesystem::remove(tempfolder);

    // string_view
    std::string str = "Hello world from a string view.";
    std::string_view sv(str);
    std::cout << sv << "\n";

    // string_view for substring
    std::string_view sw(str.c_str(), 5);
    std::cout << sw << "\n";
    std::cout << sv.substr(0, 5) << "\n";

    // std::any
    std::any abc = 123;
    std::cout << "Any accessed as an integer: " << std::any_cast<int>(abc) << "\n";

    abc = 345.678;
    std::cout << "Any accessed as an double: " << std::any_cast<double>(abc) << "\n";

    abc = true;
    std::cout << "Any accessed as a boolean: " << std::any_cast<bool>(abc) << "\n";

    // std::any has_value()
    if (abc.has_value()) {
        std::cout << "Object abc contains a value.\n";
    } else {
        std::cout << "Object abc does not contain a value.\n";
    }
    std::any bca{};
    if (bca.has_value()) {
        std::cout << "Object bca contains a value.\n";
    } else {
        std::cout << "Object bca does not contain a value.\n";
    }

    // union
    MyUnion mu;
    mu.c = 'A';
    std::cout << mu.c << "\n"; // accessing mu.x or mu.d is undefined behavior at this point
    mu.x = 123;
    std::cout << mu.x << "\n"; // accessing mu.c or mu.d is undefined behavior at this point
    mu.d = 456.789;
    std::cout << mu.d << "\n"; // accessing mu.c or mu.x is undefined behavior at this point

    // variant
    std::variant<char,int, double> myvariant {'a'}; // variant now holds a char
    std::cout << std::get<0>(myvariant) << "\n"; // obtain a data member by index
    std::cout << std::get<char>(myvariant) << "\n"; // obtain a data member by type

    myvariant = 1024; // variant now holds an integer
    std::cout << std::get<1>(myvariant) << "\n"; // by index
    try {
        std::cout << std::get<double>(myvariant) << "\n"; // by type
    } catch (const std::bad_variant_access& e) {
        std::cout << "An error has occured: " << e.what() << "\n";
    }

    myvariant = 123.345; // variant now holds a double

    // concept
    myfunction<char>(97);
    myfunction<int>(123);
    //    myfunction<double>(3.14); // Error, a floating point number is not even nor odd

    // Lambda Templates
    auto mylambdaT = []<typename T>(T param) {
        std::cout << typeid(T).name() << "\n";
    };
    std::vector<int> v1 = {1,2,3,4,5};
    mylambdaT(v1); // integer
    std::vector<double> v2 = {3.14, 123.456, 7.13};
    mylambdaT(v2); // double

    // likely - unlikely usecase
    mychoice(1);

    // likely unlikely - ifelse
    bool choice = true;
    if (choice) [[likely]] {
        std::cout << "This statement is likely to be executed.\n";
    } else [[unlikely]] {
        std::cout << "This statement is unlikely to be executed.\n";
    }

    // std::ranges
    std::vector<int> v3 = {3,5,2,1,4};
    std::ranges::sort(v);
    for (auto el: v3) {
        std::cout << el << "\n";
    }

    // filter out odd number using views
    auto oddnumbersview = v1 | std::views::filter([](int x) {return x%2 == 1;}) | std::views::filter([](int x) {return x>2;});
    for (auto el: oddnumbersview) {
        std::cout << el << "\n";
    }

    std::ranges::reverse(v1);
    for (auto el: v1) {
        std::cout << el << "\n";
    }

    // std::span
    std::vector<int> v4 = {1,2,3};
    std::span<int> myintspan = v4;
    myintspan[2] = 256;
    for (auto el: v4) {
        std::cout << el << "\n";
    }

    // fixed size span
    std::array<int,5> myarr = {1,2,3,4,5};
    std::span<int,5> myintspan1 = myarr;
    myintspan1[4] =10;
    for (auto el: myarr) {
        std::cout << el << "\n";
    }

    // mathematical constants
    std::cout << "Pi: " << std::numbers::pi << "\n";
    std::cout << "e: " << std::numbers::e << "\n";
    std::cout << "log2(e): " << std::numbers::log2e << "\n";
    std::cout << "log10(e): " << std::numbers::log10e << "\n";
    std::cout << "ln(2): " << std::numbers::ln2 << "\n";
    std::cout << "ln(10): " << std::numbers::ln10 << "\n";
    std::cout << "sqrt(2): " << std::numbers::sqrt2 << "\n";
    std::cout << "sqrt(3): " << std::numbers::sqrt3 << "\n";

    // literal suffixes for size_t
    auto x1 = 123u; // unsigned
    auto x2 = 123l; // long
    auto x3 = 123ul; // unsigned long
    auto x4 = 123ll; // long long
    // -std=c++23
    //    auto x5 = 123uz; // std::size_t
    //    auto x5 = 123z; // the signed integer type corresponding to std::size_t

    return 0;
}


























