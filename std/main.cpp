#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

// Lambda Expressions
class MyClass {
public:
    void operator()(int x) {
        std::cout << "Function object called with a parameter " << x << "\n";
    }
};

int main()
{
    // vector
    std::vector<int>v = {1,2,3,4,5};
    v.push_back(10);
    std::cout << "The third element is: " << v[2] << "\n";
    std::cout << "The fourth element is: " << v.at(3) << "\n";
    std::cout << "The vector's size is: " << v.size() << "\n";

    // array
    std::array<int, 5> arr = {1,2,3,4,5};
    for (auto el: arr) {
        std::cout << el << "\n";
    }

    // set
    std::set<int> myset = {1,9,1,3,4,5};
    myset.insert(10);
    myset.insert(42);
    for (auto el: myset) {
        std::cout << el << "\n";
    }
    std::cout << myset.size() << "\n";

    // map
    std::map<int,char> mymap = {{1,'a'}, {2,'b'}, {3,'w'}};
    mymap[3]='c';
    mymap.insert({20, 't'});
    for (auto el: mymap) {
        std::cout << el.first << ": " << el.second << "\n";
    }
    auto it = mymap.find(2);
    if (it != mymap.end()) {
        std::cout << "Found: " << it->first << ": " << it->second << "\n";
    } else {
        std::cout << "Not found.\n";
    }

    // pair
    std::pair<int,double>mypair = {123, 3.1416};
    std::cout << "The fist element is: " << mypair.first << "\n";
    std::cout << "The second element is: " << mypair.second << "\n";

    int x = 123;
    double d = 3.1416;
    std::pair<int,double> mypair1 = std::make_pair(x,d);
    std::cout << "The fist element is: " << mypair1.first << "\n";
    std::cout << "The second element is: " << mypair1.second << "\n";

    // range based for loop
    std::vector<int> v1 = {2,4,6,8,10};
    v.push_back(12);
    for (int& el: v) {
        el += 1;
    }
    for (int el: v) {
        std::cout << el << "\n";
    }

    // for string we should use const auto& specifier
    std::vector<std::string> vs = {"Hello", "World", "C++"};
    vs.push_back("Is great!");
    for (const auto& el: vs) {
        std::cout << el << "\n";
    }

    // iterator
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << "\n";
    }

    // erase using iterator
    std::vector<int> v3 = {1,2,3,4,5};
    auto iterator = v3.begin()+3;
    v3.erase(iterator);
    for (auto el: v3) {
        std::cout << el << "\n";
    }
    std::cout << v3.size() << "\n";

    // erase remove idiom
    std::vector<int> v4 = {1,2,3,4,5};
    auto it1 = v4.begin()+3;
    v4.erase(std::remove(v4.begin(), v4.end(), *it1), v4.end());
    for (auto el: v4) {
        std::cout << el << "\n";
    }

    // sort - ascending
    std::vector<int> v5 = {1, 5, 2, 15, 3, 10};
    std::sort(v5.begin(), v5.end());
    for (auto el: v5) {
        std::cout << el << "\n";
    }

    // sort - descending
    std::sort(v5.begin(), v5.end(), std::greater<int>());
    for (auto el: v5) {
        std::cout << el << "\n";
    }

    // find
    auto result = std::find(v5.begin(), v5.end(), 51);
    if (result != v5.end()) {
        std::cout << "Element found: " << *result << "\n";
    } else {
        std::cout << "Element not found.\n";
    }

    // copy
    std::vector<int> copy_from_v = {1,2,3,4,5};
    std::vector<int> copy_to_v(5); // reserve the space for 5 elements
    std::copy(copy_from_v.begin(), copy_from_v.end(), copy_to_v.begin());
    for (auto el: copy_to_v) {
        std::cout << el << "\n";
    }

    // copy - only first three element
    std::vector<int> copy_to_v1(3);
    std::copy(copy_from_v.begin(), copy_from_v.begin()+3, copy_to_v1.begin());
    for (auto el: copy_to_v1) {
        std::cout << el << "\n";
    }

    // max element
    std::vector<int> v6 = {1,2,3,4,5};
    auto it2 = std::max_element(std::begin(v6), std::end(v6));
    std::cout << "The max element in the vector is: " << *it2 << "\n";

    // min_element
    std::vector<int> v7 = {1,2,3,4,5};
    auto it3 = std::min_element(std::begin(v7), std::end(v7));
    std::cout << "The max element in the vector is: " << *it3 << "\n";

    // lambda expression
    MyClass myobject;
    myobject(123);

    auto mylambda = [](){std::cout << "Hello from a lambda expression.\n";};
    mylambda();
    // capture lambda
    int xx = 123;
    int yy = 456;
    auto lambda = [xx, yy]() {
        std::cout << "The value of x is: " << xx << "\n";
        std::cout << "The value of y is: " << yy << "\n";
    };
    lambda();

    auto lambda1 = [](int x, int y) {
        std::cout << "The value of x is: " << x << ", and y is: " << y << "\n";
    };
    lambda1(123,456);

    // lambda use case
    std::vector<int> v8 = {1,2,3,4,5,6,7,8,9,10,20,30};
    auto counteven = std::count_if(v8.begin(), v8.end(), [](int x) {return x%2 == 0;});
    std::cout << "The number of even vector elements is: " << counteven << "\n";

    // deleting a range of elements
    std::vector<int> v9 = {10,5,8,4,1,2};
    v.erase(v9.begin(), v9.begin()+3);
    for (auto el: v9) {
        std::cout << el << "\n";
    }

    // set data manipulation
    std::set<int> set = {-10,1,3,5,6,9,15};
    set.insert(-5); // insert a value of -5
    set.insert(30); // insert a value of 30
    set.erase(6);
    for (auto el: set) {
        std::cout << el << "\n";
    }
    std::cout << "The set's size is: " << set.size() << "\n";
    std::cout << "Clearing the set..." << "\n";

    auto foundit = set.find(9);
    if (foundit != set.end()) {
        std::cout << "Value found. Deleting the value...\n";
        set.erase(foundit);
        std::cout << "Element deleted.\n";
    } else {
        std::cout << "Value not found.\n";
    }

    set.clear();
    if (set.empty()) {
        std::cout << "The set is empty.\n";
    } else {
        std::cout << "The set is not empty.\n";
    }

    // inserting into map
    std::map<std::string, int> mymap1 = {{"red", 1}, {"green", 20}, {"blue", 15}};
    mymap1.insert({"magenta", 4});
    mymap1["yellow"] = 5;
    for (auto el: mymap1) {
        std::cout << el.first << ": " << el.second << "\n";
    }

    // lambda expression use case
    std::vector<int> v10 = {5,10,4,1,3,15};
    std::sort(std::begin(v10), std::end(v10), [](int x, int y) {return x > y;});
    for (auto el: v10) {
        std::cout << el << "\n";
    }

    int mycount = std::count_if(v10.begin(), v10.end(), [](int x) {return x%2 == 0;});
    std::cout << "The number of even numbers is: " << mycount << "\n";
    return 0;
}
