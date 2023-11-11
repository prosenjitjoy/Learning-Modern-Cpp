#include <iostream>

void myfunction(const std::string&);
void myprint(char);
void myprint(int);
void myprint(double);

int main() {
    // escape sequence
    std::cout << "First line\nSecond line\n";

    // fundamental types
    bool a = true;
    bool b {false};

    char c = 'a';
    std::cout << "The value of variable c is: " << c << std::endl;
    c = 'b';
    std::cout << "The new value of variable c is: " << c << std::endl;

    int x = 123;
    int y = -256;
    std::cout << "The value of x is: " << x << ", the value of y is: " << y << std::endl;
    x = 456;
    std::cout << "The value of x is: " << x << ", the value of y is: " << y << std::endl;

    int decimal = 10;
    int octal = 012;
    int hexa = 0xA;

    double d = 3.14;
    std::cout << "The value of d is: " << d << std::endl;
    d = 3.14e10;
    std::cout << "The value of d is: " << d << std::endl;

    // sizeof types
    std::cout << "The size of type char is: " << sizeof(char) << "byte(s)" << std::endl;
    std::cout << "The size of type int is: " << sizeof(int) << "byte(s)" << std::endl;
    std::cout << "The size of type long is: " << sizeof(long) << "byte(s)" << std::endl;
    std::cout << "The size of type double is: " << sizeof(double) << "byte(s)" << std::endl;

    if (x) {
        std::cout << "The condition is true.\n";
    } else {
        std::cout << "The condition is false.\n";
    }

    // Argument passing by const reference

    std::string s = "Hello World!";
    myfunction(s);

    // Function overloading
    myprint('c');
    myprint(123);
    myprint(456.789);

    // Operator new and delete
    int* p = new int;
    *p = 123;
    std::cout << "The pointed-to value is: " << *p << "\n";
    delete p;

    // Allocate memory for an array
    int* ap = new int[3];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    std::cout << "The values are: " << p[0] << " " << p[1] << " " << p[2] << "\n";
    delete[] ap;

    return 0;
}

void myfunction(const std::string& byconstreference) {
    std::cout << "Arguments passed by const reference: " << byconstreference << std::endl;
}

void myprint(char param) {
    std::cout << "Printing a character: " << param << "\n";
}

void myprint(int param) {
    std::cout << "Printing an integer: " << param << "\n";
}

void myprint(double param) {
    std::cout << "Printing a double: " << param << "\n";
}
