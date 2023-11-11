#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>

class MyClass {
public:
    void printmessage() {
        std::cout << "Hello from a class.\n";
    }
};

// polymorphic class with unique pointer
class MyBaseClass {
public:
    virtual void printmessage() {
        std::cout << "Hello from a base class.\n";
    }
};

class MyDerivedClass: public MyBaseClass {
public:
    void printmessage() {
        std::cout << "Hello from a derived class.\n";
    }
};

// Unique pointer to an Object of a class
class MyUniquePointerClass {
private:
    int x;
    double d;
public:
    MyUniquePointerClass(int xx, double dd): x{xx}, d{dd} {}
    void printdata() {
        std::cout << "Data members values are: " << x << " and: " << d << "\n";
    }
};

// simple polymorphism
class BaseClass {
public:
    virtual void dowork() = 0;
    virtual ~BaseClass() {}
};

class DerivedClass: public BaseClass {
public:
    void dowork() override {
        std::cout << "Do work from a DerivedClass.\n";
    }
};

class SecondDerivedClass: public BaseClass {
public:
    void dowork() override {
        std::cout << "Do work from a SecondDerivedClass.\n";
    }
};

int main()
{
    // unique smart pointer
    std::unique_ptr<int> p(new int{123});
    std::cout << *p << "\n";

    std::unique_ptr<int> p1 = std::make_unique<int>(456);
    std::cout << *p1 << "\n";

    // unique pointer - class object
    std::unique_ptr<MyClass> cp = std::make_unique<MyClass>();
    cp->printmessage();

    // polymorphic class with unique pointer
    std::unique_ptr<MyBaseClass> bcp = std::make_unique<MyDerivedClass>();
    bcp->printmessage();
    std::unique_ptr<MyBaseClass> bcp1 = std::make_unique<MyBaseClass>();
    bcp1->printmessage();

    // shared pointer
    std::shared_ptr<int> sp1 = std::make_shared<int>(143);
    std::shared_ptr<int> sp2 = sp1;
    std::shared_ptr<int> sp3 = sp1;
    std::cout << "Shared pointer 1 points at: " << *sp1 << "\n";
    std::cout << "Shared pointer 2 points at: " << *sp2 << "\n";
    std::cout << "Shared pointer 3 points at: " << *sp3 << "\n";

    // static_cast conversion
    int x = 123;
    double d = 456.789;
    bool b = true;
    double doubleresult = static_cast<double>(x);
    std::cout << "Int to double: " << doubleresult << "\n";
    int intresult = static_cast<int>(d); // double to int
    std::cout << "Double to int: " << intresult << "\n";
    bool boolresult = static_cast<bool>(x); // int to bool
    std::cout << "Int to bool: " << boolresult << "\n";

    // unique pointer to an object of a class
    std::unique_ptr<MyUniquePointerClass> upc = std::make_unique<MyUniquePointerClass>(23, 56.789);
    upc->printdata();

    // simple polymorphism
    std::unique_ptr<BaseClass> bc = std::make_unique<DerivedClass>();
    bc->dowork();
    std::unique_ptr<BaseClass> bc1 = std::make_unique<SecondDerivedClass>();
    bc1->dowork();

    // File Streams
    std::fstream fs{"myfile.txt"};
    std::string s;

//    // read one line at a time
//    while (fs) {
//        std::getline(fs, s); // read each line into string
//        std::cout << s << "\n";
//    }

    // read one character at a time
    char c;
    while (fs >> std::noskipws >> c) {
        std::cout << c;
    }

    // write to a file
//    std::fstream fs1{"myoutputfile.txt", std::ios::out};
//    fs1 << "First line of text.\n";
//    fs1 << "Second line of text.\n";
//    fs1 << "The third line of text.\n";

//    // append to a file
//    std::fstream fs2{"myoutputfile.txt", std::ios::app};
//    fs2 << "This is appended text.\n";
//    fs2 << "This is also an appended text.\n";

    std::fstream fs3{"myoutputfile.txt", std::ios::out};
    std::string s1 = "The first string.\n";
    std::string s2 = "The second string.\n";
    fs3 << s1 << s2;

    // String Streams
    std::stringstream ss{"Hello World.\n"};
    std::cout << ss.str();
    ss << "I love C++.";
    std::cout << ss.str();
    std::string str = ss.str();
    std::cout << str;

    char ac = 'A';
    int ax = 123;
    double ad = 456.789;
    std::stringstream ss1;
    ss1 << "The char is: " << ac << ", int is: " << ax << ", and double is: " << ad << "\n";
    std::cout << ss1.str();

    // output data from a stream into object
    std::string s3 = "A 123 456.78";
    std::stringstream ss2{s3};
    char c1;
    int x1;
    double d1;
    ss2 >> c1 >> x1 >> d1;
    std::cout << c1 << " " << x1 << " " << d1 << "\n";
    return 0;
}
