#include <chrono>
#include <concepts>
#include <iterator>
#include <list>
#include <map>
#include <print>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

// const int MAX_EMAILS = 1'000'000;
const int MAX_EMAILS = 10'000;

struct Email {
    std::string subject;
    std::string body;
    std::string from;
    std::chrono::time_point<std::chrono::system_clock> datetime;
};

void print(const std::list<int>& list) {
    for (const auto& i : list) {
        std::print("{} ", i);
    }
    std::println();
}

struct Point {
    float x;
    float y;
    float z;
    Point(float px, float py, float pz) : x{px}, y{py}, z{pz} {
    }
    Point(Point&& p) : x{p.x}, y{p.y}, z{p.z} {
    }
};

bool validate_parentheses(const std::string& str) {
    std::stack<char> st;

    for (const auto& ch : str) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.size() == 0) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

template <typename T>
void print(T container) {
    while (!container.empty()) {
        std::print("{} ", container.top());
        container.pop();
    }
    std::println();
}

template <typename Iter>
typename std::iterator_traits<Iter>::difference_type distance(Iter first,
                                                              Iter last) {
    using category = std::iterator_traits<Iter>::iterator_category;
    if constexpr (std::is_same_v<category, std::random_access_iterator_tag>) {
        return last - first;
    }
    typename std::iterator_traits<Iter>::difference_type count;
    for (; first != last; ++count, first++) {
    }
    return count;
}

template <typename T>
concept addable = requires(T obj) { obj + obj; };

template <addable T>
class Wallet {};

template <typename T>
int dist(T start, T end) {
    if constexpr (std::is_same_v<
                      typename std::iterator_traits<T>::iterator_category,
                      std::random_access_iterator_tag>) {
        return end - start;
    } else {
        int count = 0;
        while (start != end) {
            ++count;
            ++start;
        }
        return count;
    }
}

template <typename T>
struct node {
    node(const T& it) : item{it}, next{nullptr}, prev{nullptr} {
    }
    T item;
    node<T>* next;
    node<T>* prev;
};

template <typename T>
class LinkedList {
  public:
    void push_front(const T& item) {
        node<T>* new_node = new node<T>(item);
        if (m_head != nullptr) {
            new_node->next = m_head->next;
            if (m_head->next != nullptr) {
                m_head->next->prev = new_node;
            }
        }
        new_node->next = m_head;
        m_head = new_node;
    }

  private:
    node<T>* m_head;
};

int main() {
    Email inbox[MAX_EMAILS];
    std::println("{}", MAX_EMAILS);

    std::vector<int> vec;
    vec.reserve(MAX_EMAILS);
    vec.push_back(4);
    vec.push_back(2);
    vec.shrink_to_fit();

    for (const auto& elem : vec) {
        std::println("{}", elem);
    }

    // std::println("{} {}", vec[6], vec.at(6));

    std::list<double> lst;
    lst.push_back(4.2);
    lst.push_front(3.14);

    for (const auto& elem : lst) {
        std::print("{} ", elem);
    }

    std::list<int> l1 = {0, 1, 2, 5, 7, 12};
    std::list<int> l2 = {-3, 6, 8};
    l1.merge(l2);
    print(l1);  // prints –3 0 1 2 5 6 7 8 12
    print(l2);  // prints nothing because l2 is empty

    std::list<int> l3 = {4, 9, 15, 23};
    l1.splice(l1.begin(), l3);
    print(l1);  // prints 4 9 15 23 –3 0 1 2 5 6 7 8 12
    print(l3);  // prints nothing because l3 is also empty

    std::vector<Point> points;
    points.push_back(Point(1.1, 2.2, 3.3));
    auto& ref = points.emplace_back(2.2, 3.3, 4.4);
    std::println("x: {}, y: {}, z: {}", ref.x, ref.y, ref.z);

    for (const auto& elem : points) {
        std::println("x: {}, y: {}, z: {}", elem.x, elem.y, elem.z);
    }

    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty()) {
        std::print("{} ", st.top());
        st.pop();
    }
    std::println();
    // std::println("{}", st.top());  // crushes as we try to remove nonexist
    // item

    std::queue<char> q;
    q.push('a');
    q.push('b');
    q.push('c');
    std::println("{}", q.front());
    std::println("{}", q.back());
    q.pop();
    std::println("{}", q.front());

    std::string check = "(a + b + (((x * y) - (a / b)) / 4)";
    std::println("{}", validate_parentheses(check));

    std::vector<int> v{2, 6, 3, 0, 12, -7};
    std::priority_queue<int, std::vector<int>> p1;
    for (int i : v) {
        p1.push(i);
    }
    // prints 12 6 3 2 0 –7 since the default underlying
    // data structure for a priority_queue is a max heap
    print(p1);

    // by passing std::greater<int> we turn our priority_queue to a min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> p2;
    for (int i : v) {
        p2.push(i);
    }
    print(p2);  // prints –7 0 2 3 6 12

    std::vector<int>::iterator it{v.begin()};
    while (it != v.end()) {
        std::print("{}, ", *it);
        it++;
    }
    std::println();
    std::println("{}", dist(v.begin(), v.end()));

    std::set<int> s{1, 5, 2, 4, 4, 4, 3};
    std::println("{}", s.size());

    std::map<int, std::string> numbers;
    numbers[3] = "three";
    numbers[4] = "four";
    std::println("{}", numbers[3]);

    return 0;
}
