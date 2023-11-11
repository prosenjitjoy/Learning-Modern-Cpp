#include <iostream>

class MyClass {
private:
    char c;
    long l;
    double d;
    int* p;
public:
    // Class constructor
    MyClass(char cc = 'c', long ll = 23, double dd = 23.32, int pp = 2): c{cc}, l{ll}, d{dd}, p{new int{pp}} {
        std::cout << "Default constructor invoked.\n";
    }

    // User defined copy constructor
    MyClass(const MyClass& rhs): c{rhs.c}, l{rhs.l}, d{rhs.d}, p{new int{*rhs.p}} {
        std::cout << "User-defined copy constructor invoked.\n";
    }

    // Copy assignment
    MyClass& operator=(const MyClass& rhs) {
        // implement the copy logic here
        return *this;
    }

    // User defined move constructor
    MyClass(MyClass&& rhs): c{std::move(rhs.c)}, l{std::move(rhs.l)}, d{std::move(rhs.d)}, p{new int{std::move(*rhs.p)}} {
        std::cout << "Move constructor invoked.\n";
    }

    // Move assignment
    MyClass& operator=(MyClass&& rhs) {
        c = std::move(rhs.c);
        l = std::move(rhs.l);
        d = std::move(rhs.d);
        p = new int{std::move(*rhs.p)};
        std::cout << "Move assignment operator invoked.\n";
        return *this;
    }

    // prefix operator ++
    MyClass& operator++() {
        ++c;
        ++l;
        ++d;
        ++*p;
        std::cout << "Prefix operator ++ invoked.\n";
        return *this;
    }

    // postfix operator ++
    MyClass operator++(int) {
        MyClass tmp(*this); // create a copy
        operator++(); // invoke the prefix operator overload
        std::cout << "Postfix operator ++ invoked.\n";
        return tmp;
    }

    // prefix operator +=
    MyClass& operator+=(const MyClass& rhs) {
        c += rhs.c;
        l += rhs.l;
        d += rhs.d;
        *p += *rhs.p;
        std::cout << "invoked the overloaded += operator.\n";
        return *this;
    }

    // destructor
    ~MyClass() {
        delete p;
        std::cout << "Destructor invoked.\n";
    }

    void doSomething();
    void doAnything();
    void printX();
};

// Inheritance and Polymorphism
class MyBaseClass {
private:
    long l;
protected:
    char c;
    int x;
public:
    virtual void dowork() {
        std::cout << "Hello from a base class.\n";
    }
    virtual ~MyBaseClass() {}
};

class MyDerivedClass : public MyBaseClass {
public:
    // c and x also accessible here
    // l is not accessible here

    void dowork() {
        std::cout << "Hello from a derived class.\n";
    }
};

// Pure virtual functions, abstract class, interfaces
class MyAbstractClass {
public:
    virtual void dowork() = 0;
    virtual ~MyAbstractClass() {}
};

class MyDerivedAbstractClass : public MyAbstractClass {
public:
    void dowork() {
        std::cout << "Hello from a derived abstract class.\n";
    }
};

class Person {
private:
    std::string name;
public:
    explicit Person(const std::string& aname) : name{aname} {}
    std::string getname() const { return name; }
};

class Student : public Person {
private:
    int semester;
public:
    Student(const std::string& aname, const int& asemester) : Person::Person{aname}, semester{asemester} {}
    int getsemester() const { return semester; }
};

int main() {
    std::cout << "Hello World!" << std::endl;
    MyClass o;
    o.doSomething();
    o.doAnything();
    o.printX();
    MyClass o1 = o;
    o.printX();
    MyClass o2 = std::move(o1);
    // MyClass o2{std::move(o1};
    MyClass o3{'o', 44, 2.354, 7};
    o3.printX();
    o3 = std::move(o2);
    o3.printX();
    o3.operator++();
    o3.printX();
    ++o3;
    o3.printX();
    o3++;
    o3.printX();
    o3.operator++(0);
    o3.printX();
    o3 += o;
    o3.printX();


    MyDerivedClass mdc;
    // but not accessible here because these are protected
//    mdc.c = 'a';
//    mdc.x = 123;

    MyBaseClass* mbc = new MyDerivedClass;
    mbc->dowork();
    delete mbc;

    // can not create object of abstract classes
//    MyAbstractClass test;

    MyAbstractClass *mac = new MyDerivedAbstractClass;
    mac->dowork();
    delete mac;

    // Exercises
    Person person{ "John Doe" };
    std::cout << person.getname() << "\n";
    Student student{ "Jane Doe", 2 };
    std::cout << student.getname() << "\n";
    std::cout << "The semester is: " << student.getsemester() << "\n";

    return 0;
}

// Outside class
void MyClass::doSomething() {
    std::cout << "Hello World from a class\n";
}

void MyClass::doAnything() {
    std::cout << "Hello World from a class.\n";
}

void MyClass::printX() {
    std::cout << "c = " << c << ", l = " << l << ", d = " << d << ", p = " << *p << "\n";
}

