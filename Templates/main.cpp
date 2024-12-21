#include <iostream>
#include <print>
#include <string>
#include <vector>

// define a primary template
template <class T>
T app_max(T a, T b) {
    return a > b ? a : b;
}

// explicit specialization for T=std::string
template <>
std::string app_max(std::string a, std::string b) {
    return a[0] > b[0] ? a : b;
}

// primary class template
template <class T>
struct X {
    X(T init) : m{init} {
    }
    T increase() {
        return ++m;
    }
    T m;
};

// specialized class template for char types
template <>
struct X<char> {
    X(const char init) : m{init} {
    }
    char increase() {
        return (m < 127) ? ++m : (m = -128);
    }
    char toUpperCase() {
        if (m >= 'a' && m <= 'z') {
            m += 'A' - 'a';
        }
        return m;
    }
    char m;
};

// a class template with zero or more type parameters
template <class... Args>
class ClassX {
    //
};

// a function template with zero or more type parameters
template <class... Args>
void foo() {
}

double my_min(double n) {
    return n;
}

template <typename... Args>
double my_min(double n, Args... args) {
    return std::min(n, my_min(args...));
}

// non-type template parameter
template <int N>
class V {
  public:
    V(int init) {
        for (int i = 0; i < N; ++i) {
            a[i] = init;
        }
    }
    int a[N];
};

template <const char *msg>
void foo() {
    std::println("{}", msg);
}
// compile time constant value
extern const char str1[] = "test 1";
constexpr char str2[] = "test 2";

/*
std::ostream& operator<<(std::ostream& os, const X<T,Args...>& objs) {
    for (auto const& obj: objs) {
        os << obj << ' ';
    }
    return os;
 */

// template template parameter
template <class T, template <class, class...> class X, class... Args>
std::ostream &operator<<(std::ostream &os, const X<T, Args...> &objs) {
    for (auto const &obj : objs) {
        os << obj << " ";
    }
    return os;
}

// primary class template is_void
template <class T>
struct is_void {
    static const bool value = false;
};

// "<>" means a full specializationi of template class is_void
template <>
struct is_void<void> {
    static const bool value = true;  // only true of T=void
};

// primary class template is_pointer
template <class T>
struct is_pointer {
    static const bool value = false;
};
// "class T" in "<>" means partial specialization
// <T*> means partial specialization only for type T*
template <class T>
struct is_pointer<T *> {
    static const bool value = true;
};

struct Z {};

int main() {
    std::println("Hello World!");
    int a{3}, b{6};
    std::string s1{"hello"}, s2{"world"};
    std::println("{}", app_max<int>(a, b));
    std::println("{}", app_max<std::string>(s1, s2));
    char *x = "abc", *y = "efg";  // Line C
    std::println("{}", app_max(x, y));

    X<int> x1(5);
    std::println("{}", x1.increase());
    X<char> x2('b');
    // std::println("{}", x2.increase());
    std::println("{}", x2.toUpperCase());
    double v1 = my_min(2);
    double v2 = my_min(2, 3);
    double v3 = my_min(2, 3, 4, 5, 4.7, 5.6, 9.9, 0.1);
    std::println("v1: {}, v2: {}, v3: {}", v1, v2, v3);

    V<5> xx(1);  // x.a is an array of 5 int, initialized as all 1's
    xx.a[4] = 10;
    xx.a[2] = 7;
    for (auto &e : xx.a) {
        std::println("{}", e);
    }
    foo<str1>();
    foo<str2>();

    std::vector<float> v{3.14f, 4.2f, 7.9f, 8.08f};
    std::cout << v << std::endl;

    bool test = is_void<void>::value;
    std::println("{}", test);
    int tmp{4};
    int &t = tmp;
    test = is_pointer<int *>::value;
    std::println("{}\n", test);

    std::println("{}", std::is_void<void>::value);
    std::println("{}", std::is_void<int>::value);
    std::println("{}", std::is_pointer<Z *>::value);
    std::println("{}", std::is_pointer<Z>::value);
    std::println("{}", std::is_pointer<Z &>::value);
    std::println("{}", std::is_pointer<int *>::value);
    std::println("{}", std::is_pointer<int **>::value);
    std::println("{}", std::is_pointer<int[10]>::value);
    std::println("{}", std::is_pointer<std::nullptr_t>::value);

    return 0;
}
