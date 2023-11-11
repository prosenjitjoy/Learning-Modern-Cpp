#include <iostream>
#include "mylibrary.h"

// user defined namespace
namespace MyNameSpace {
int x;
double d;
void mynamespacefunction();
}
//using namespace MyNameSpace;

// extending namespace by separate namespace declaration
namespace MyNameSpace {
char c;
bool b;
}

// two namespaces with different names can hold an object with same name
namespace MySecondNameSpace {
int x;
}

void MyNameSpace::mynamespacefunction() {
    std::cout << "Hello World from a function inside a namespace.\n";
}

// nested namespace
namespace A {
namespace B {
void mynestednamespacefunction();
}
}

void A::B::mynestednamespacefunction() {
    std::cout << "Hello World from a function inside a nested namespace.\n";
}

// array function argument decays to pointer
void mytestfunction(int arg[]) {
    std::cout << *(arg+1) << "\n";
}

// Explicit conversion - dynamic cast
class MyBaseClass {
public:
    virtual ~MyBaseClass() {}
};

class MyDerivedClass : public MyBaseClass {};
class MyUnrelatedClass {};

int main()
{
    MyNameSpace::x = 123;
    MyNameSpace::d = 423.423;
    MyNameSpace::c = 'a';
    MyNameSpace::b = true;

    std::cout << "int: " << MyNameSpace::x << ", double: " << MyNameSpace::d << "\n";

    MySecondNameSpace::x = 456;
    std::cout << "The 1st x is: " << MyNameSpace::x << ", the 2nd x is: " << MySecondNameSpace::x << "\n";

    // uses of function declared in myheader.h
    myfunction();
    MyNameSpace::mynamespacefunction();

    // nested namespace function usage
    A::B::mynestednamespacefunction();

    // implicit conversions
    char mychar = 'c';
    int myint = 64;
    double mydouble = 456.789;
    bool mybool = true;
    mychar = mybool;
    std::cout << mychar << "\n";
    myint = mydouble; // the decimal part is lost

    // pointer of any type can be converted to void* type
    int x = 123;
    int* pint = &x;
    void* pvoid = pint;
    int* pint2 = static_cast<int*>(pvoid);
    std::cout << *pint2 << "\n";

    int arr[5] = {1,22,3,4,5};
    int* p = arr;
    std::cout << *(p+2) << "\n";

    // decays to a pointer
    mytestfunction(arr);

    // explicit conversions
    auto myinteger = static_cast<int>(123.234);
    std::cout << myinteger << "\n";

    // dynamic_cast
    MyBaseClass* base = new MyDerivedClass;
    MyDerivedClass* derived = new MyDerivedClass;
    MyUnrelatedClass* unrelated = new MyUnrelatedClass;

    // base to derived
    if (dynamic_cast<MyDerivedClass*>(base)) {
        std::cout << "OK. Convertible.\n";
    } else {
        std::cout << "Not convertible.\n";
    }

    // derived to base
    if (dynamic_cast<MyBaseClass*>(derived)) {
        std::cout << "OK. Convertible.\n";
    } else {
        std::cout << "Not convertible.\n";
    }

    // base to unrelated
    if (dynamic_cast<MyUnrelatedClass*>(base)) {
        std::cout << "OK. Convertible.\n";
    } else {
        std::cout << "Not convertible.\n";
    }

    // derived to unrelated
    if (dynamic_cast<MyUnrelatedClass*>(derived)) {
        std::cout << "OK. Convertible.\n";
    } else {
        std::cout << "Not convertible.\n";
    }

    delete base;
    delete derived;
    delete unrelated;

    // Exceptions
    try {
        std::cout << "Let's assume some error occurred in our program.\n";
        std::cout << "We throw an exception of type int, for example.\n";
        throw int{7};
        // the following will not execute as the control has been transferred to a catch clause
        std::cout << "This signals that something went wrong.\n";
        throw std::string{"Some string error"};
    } catch (int e) {
        std::cout << "Integer exception raised!\n";
        std::cout << "The execption has a value of " << e << "\n";
    } catch (std::string e) {
        // catch and handle the exception
        std::cout << "String exception raised!\n";
        std::cout << "The execption has a value of " << e << "\n";
    }

    try {
        bool someflag = true;
        bool someotherflag = true;
        std::cout << "We can have multiple throw execptions.\n";
        if (someflag) {
            std::cout << "Throwing an int execption.\n";
            throw int{123};
        }
        if (someotherflag) {
            std::cout << "Throwing a string execption.\n";
            throw std::string{"Some string error"};
        }
    } catch (int e) {
        std::cout << "Integer exception raised!\n";
        std::cout << "The execption has a value of " << e << "\n";
    } catch (std::string e) {
        // catch and handle the exception
        std::cout << "String exception raised!\n";
        std::cout << "The execption has a value of " << e << "\n";
    }

    return 0;
}
