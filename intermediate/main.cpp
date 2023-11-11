#include <iostream>

using namespace std;

// static specifier used inside function
void myfunction() {
    // static variable defined only the first time, skipped every other time
    static int x = 0;
    x++;
    std::cout << "Functio ran: " << x << " time(s).\n";
}

// static specifier used inside class
class MyClass {
public:
    static int x; // declare a static data member
    static void myStaticFunction(); // declare a static member function
};

int MyClass::x = 123; // define a static data member
void MyClass::myStaticFunction() {
    std::cout << "Hello World from a static member function.\n";
}

// function template - one parameter
template <typename T>
void myTemplateFunction(T param) {
    std::cout << "The value of a parameter is: " << param << "\n";
}

// function template - two parameter
template <typename T, typename U>
void myTemplateFunctionMulti(T t, U u) {
    std::cout << "The first parameter is: " << t << "\n";
    std::cout << "The second parameter is: " << u << "\n";
}

// class template
template <typename T>
class MyTemplateClass {
private:
    T x;
public:
    explicit MyTemplateClass(const T& xx) : x{xx} {}
    T getvalue() const { return x; }

};

template <typename T>
class MyTemplateClassOutside {
private:
    T x;
public:
    MyTemplateClassOutside(T xx);
};

template<typename T>
MyTemplateClassOutside<T>::MyTemplateClassOutside(T xx) : x{xx} {
    std::cout << "Constructor invoked. The valud of x is: " << x << "\n";
}

// template specialization
template <typename T>
void myfunc(T arg) {
    std::cout << "The value of an argument is: " << arg << "\n";
}
template <> // template specialization code follows
void myfunc(int arg) {
    std::cout << "This is a specialization for an int. The value is: " << arg << "\n";
}

// Unscoped enum
enum MyEnum {
    myfirstvalue = 10,
    mysecondvalue,
    mythirdvalue
};

// Scoped enum
enum class MyScopedEnum {
    firstvalue = 22,
    secondvalue,
    thirdvalue = 54
};

// static use case
void functionCallCounter() {
    static int counter = 0;
    counter++;
    std::cout << "The function is called " << counter << " time(s).\n";
}

// static data member
class StaticDataMemberClass {
public:
    static std::string name;
};

std::string StaticDataMemberClass::name = "John Doe";

// static member function
class StaticMemberFunctionClass {
public:
    static void mystaticfunction();
    void mynormalfunction();
};

void StaticMemberFunctionClass::mystaticfunction() {
    std::cout << "Hello World from a static member function.\n";
}

void StaticMemberFunctionClass::mynormalfunction() {
    std::cout << "Hello World from a regular member function.\n";
}

// function template
template <typename T>
T mysum(T x, T y) {
    return x + y;
}

// class template
template <typename T>
class ClassTemplate {
private:
    T x;
public:
    explicit ClassTemplate(T xx) : x{xx} {}
    T getx() const { return x; }
    void setx(T ax) { x = ax; }
};

// scoped enum
enum class Days {
    Montag,
    Dienstag,
    Mittwoch,
    Donnerstag,
    Freitag,
    Samstag,
    Sonntag,
};

// enum in a switch
enum class Colors {
    Red,
    Green,
    Blue
};

int main()
{
    myfunction(); // x == 1
    myfunction(); // x == 2;
    myfunction(); // x == 3

    MyClass::x = 245; // access a static data member
    std::cout << "Static data member value is: " << MyClass::x << "\n";

    MyClass::myStaticFunction(); // access a static member function

    // function templates
    myTemplateFunction<long>(123);
    myTemplateFunction<double>(123.456);
    myTemplateFunction<char>('A');

    int x = 123;
    double d = 456.789;
    myTemplateFunctionMulti<int,double>(x, d);

    // class templates
    MyTemplateClass<int> o{123};
    std::cout << "The value of x is: " << o.getvalue() << "\n";
    MyTemplateClass<double> o2 {456.789};
    std::cout << "The value of x is: " << o2.getvalue() << "\n";

    // class template - outside definition
    MyTemplateClassOutside<int> mcto{123};
    MyTemplateClassOutside<double> mtco1{456.789};

    // template specialization
    myfunc<char>('A');
    myfunc<double>(345.679);
    myfunc<int>(123); // invokes specialization

    // enumeration type variable declaration
    MyEnum myenum = myfirstvalue;
    myenum = mysecondvalue;
    std::cout << myenum << "\n";

    // scoped enum
    MyScopedEnum myscopedenum = MyScopedEnum::firstvalue;
    myscopedenum = static_cast<MyScopedEnum>(54);
    std::cout << static_cast<int>(myscopedenum) << "\n";
    if (myscopedenum == MyScopedEnum::thirdvalue) {
        std::cout << "Got it!\n";
    }

    // static variable usecase
    functionCallCounter();
    functionCallCounter();
    for (int i=0;i<5;i++) {
        functionCallCounter();
    }

    // static data member
    std::cout << "Static data member value: " << StaticDataMemberClass::name << "\n";
    StaticDataMemberClass::name = "Jane Doe";
    std::cout << "Static data member value: " << StaticDataMemberClass::name << "\n";

    // Static member function
    StaticMemberFunctionClass::mystaticfunction();
    StaticMemberFunctionClass obj;
    obj.mynormalfunction();
    obj.mystaticfunction();

    // function template
    int intresult = mysum<int>(10, 10);
    std::cout << "The integer sum result is: " << intresult << "\n";
    double doubleresult = mysum<double>(123.34, 783.134);
    std::cout << "The double sum result is: " << doubleresult << "\n";

    // class template
    ClassTemplate<int> ct{23};
    std::cout << "The value of the data member is: " << ct.getx() << "\n";
    ct.setx(345);
    std::cout << "The value of the data member is: " << ct.getx() << "\n";

    ClassTemplate<double> ct1{34.3};
    std::cout << "The value of the data member is: " << ct1.getx() << "\n";
    ct1.setx(6.28);
    std::cout << "The value of the data member is: " << ct1.getx() << "\n";

    // scoped enum
    Days myday = Days::Freitag;
    std::cout << "The enum value is now Friday.\n";
    if (myday == Days::Freitag) {
        myday = Days::Mittwoch;
    }
    std::cout << "The enum valus is now Wednesday.\n";

    // enum in a switch
    Colors mycolors = Colors::Green;
    switch (mycolors) {
    case Colors::Red:
        std::cout << "The color is Red.\n";
        break;
    case Colors::Green:
        std::cout << "The color is Green.\n";
        break;
    case Colors::Blue:
        std::cout << "The color is Blue.\n";
        break;
    default:
        break;
    }

    return 0;
}
