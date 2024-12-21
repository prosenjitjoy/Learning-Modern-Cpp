#include <deque>
#include <map>
#include <print>
#include <set>
#include <string>
#include <type_traits>

// template <unsigned long X>
// class SimpleFactorial {
//   public:
//     enum {
//         val = X * SimpleFactorial<X - 1>::val,
//     };
// };
// template <>
// class SimpleFactorial<0> {
//   public:
//     enum {
//         val = 1,
//     };
// };

constexpr unsigned long SimpleFactorial(unsigned long X) {
    return (X == 0) ? 1 : X * SimpleFactorial(X - 1);
}

constexpr unsigned long SimpleFibonacci(unsigned long X) {
    return (X == 0)  ? 0
           : (X < 2) ? 1
                     : SimpleFibonacci(X - 2) + SimpleFibonacci(X - 1);
}

template <size_t x, size_t y>
class FindPrime {
  public:
    constexpr static bool val = (x % y != 0) && FindPrime<x, y - 1>::val;
};

template <size_t x>
class FindPrime<x, 2> {
  public:
    constexpr static bool val = (x % 2 != 0);
};

template <size_t x>
class Prime {
  public:
    constexpr static bool val = FindPrime<x, x / 2>::val;
};

template <>
class Prime<3> {
  public:
    constexpr static bool val = true;
};

template <>
class Prime<2> {
  public:
    constexpr static bool val = true;
};

template <>
class Prime<1> {
  public:
    constexpr static bool val = false;
};

template <>
class Prime<0> {
  public:
    constexpr static bool val = false;
};

constexpr int gcd(short x, short y) {
    while (y != 0) {
        int tmp{y};
        y %= x;
        x = tmp;
    }
    return x;
}

template <class T, class... Args>
void print(T const &first, Args const &...pack) {
    std::print("{} ", first);
    if constexpr (sizeof...(pack) > 0) {
        print(pack...);
    }
}

template <class T>
std::string foo(T const &val) {
    if constexpr (std::is_convertible_v<T, std::string>) {
        return val;
    } else {
        return std::to_string(val);
    }
}

enum numbers {
    one = 1,
    two,
    three,
    four,
};

template <long X>
void dismem(int (*)[X % 2 == 0] = 0) {
    std::println("even");
}
template <long X>
void dismem(int (*)[X % 2 == 1] = 0) {
    std::println("odd");
}

template <class T>
typename std::enable_if<(sizeof(T) > 4)>::type custom_enable() {
    std::println("enabled");
}

namespace my_lib {
// implementation for random access iterators
template <typename X>
constexpr bool what_random_access_iterator =
    std::is_convertible<typename std::iterator_traits<X>::iterator_category,
                        std::random_access_iterator_tag>::value;

template <typename X, typename Dist>
std::enable_if_t<what_random_access_iterator<X>> advance(X &x, Dist y) {
    x += y;
}

// implementation for bidirectional iterators
template <typename X>
constexpr bool what_bidirectional_iterator =
    std::is_convertible<typename std::iterator_traits<X>::iterator_category,
                        std::bidirectional_iterator_tag>::value;

template <typename X, typename Dist>
std::enable_if_t<what_bidirectional_iterator<X> &&
                 !what_random_access_iterator<X>>
advance(X &x, Dist y) {
    if (y > 0) {
        for (; y > 0; ++x, --y) {
        }
    } else {
        for (; y < 0; --x, ++y) {
        }
    }
}

// implementation for all other iterators
template <typename X, typename Dist>
std::enable_if_t<!what_bidirectional_iterator<X> &&
                 !what_random_access_iterator<X>>
advance(X &x, Dist y) {
    if (y < 0) {
        throw "advance(): invalid category for negative y";
    }
    while (y > 0) {
        ++x;
        --y;
    }
}

}  // namespace my_lib

namespace my_lib2 {
template <bool Argument>
using bool_constant = std::integral_constant<bool, Argument>;
using true_type = std::bool_constant<true>;
using false_type = std::bool_constant<false>;
}  // namespace my_lib2

class Person {
  public:
    Person(float x = 0.0) : m_x{x} {
    }
    operator float() {
        return m_x;
    }

  private:
    float m_x;
};

struct Sirius {
    int i;
};
struct Base {
    virtual void foo() {
    }
};
struct Derived : Base {};
struct Aludra {
    virtual ~Aludra() = default;
};

class A {
  public:
    virtual void foo() = 0;
};

int main() {
    // const auto x = SimpleFactorial<4>::val;
    constexpr auto x = SimpleFactorial(4);
    static_assert(x == 24, "Factorial of 4");

    constexpr auto y = Prime<7>::val;
    static_assert(y == true, "7 is a Prime number");
    std::println("{}", y);

    // int a{24};
    // constexpr int result = a;
    const int b{24};
    constexpr int result_2 = b;

    constexpr short i = gcd(15, 25);
    int arr[gcd(5, 4)];
    short aa{11}, bb{24};
    // constexpr short res = gcd(aa, bb);

    // constexpr std::map<std::string, int> cxpr_mp{{"one", 1}, {"two", 2}};
    const std::map<std::string, int> c_mp{{"one", 1}, {"two", 2}};
    print(3.14, "templates", 55);
    std::println();
    auto res = foo("example");
    std::println("{}", typeid(res).name());

    dismem<one>();
    dismem<four>();

    std::map<std::string, short> mp{{"one", 1}, {"two", 2}};
    custom_enable<decltype(mp)>();
    custom_enable<const char *>();
    auto size = sizeof(mp);
    std::println("{}", size);

    std::set<int> st{1, 14, 5, 2};
    auto it = st.begin();
    my_lib::advance(it, 3);
    std::println("{}", *it);
    std::deque<std::string> dq{"hello", "some", "other"};
    auto it2 = dq.begin();
    my_lib::advance(it2, 2);
    std::println("{}", *it2);

    using my_type = bool;
    const my_type mt = 0;
    std::println("{}", my_lib2::bool_constant<mt>::value);

    std::println("{}", std::is_void_v<int>);
    std::println("{}", std::is_null_pointer_v<decltype(nullptr)>);
    std::println("{}", std::is_integral_v<int *>);
    std::println("{}", std::is_array_v<int[]>);
    std::println("{}", std::is_fundamental_v<decltype(nullptr)>);
    std::println("{}", std::is_arithmetic_v<Person>);

    std::println("{}", std::is_polymorphic_v<Aludra>);
    std::println("{}", std::is_abstract_v<A>);

    constexpr auto fib = SimpleFibonacci(7);
    std::println("{}", fib);
    return 0;
}
