#include <algorithm>
#include <iostream>
#include <memory>
#include <print>
#include <unordered_map>

#include "product.h"

std::unordered_map<long, long> cache;
long factorial(long n) {
    if (n <= 1) {
        return 1;
    }
    if (cache.contains(n)) {
        return cache[n];
    }
    cache[n] = n * factorial(n - 1);
    return cache[n];
}

void print_sorted() {
    short* arr{new short[420]};
    // short arr[420];
    for (int i = 0; i < 420; i++) {
        std::cin >> arr[i];
        if (arr[i] <= 0) {
            delete[] arr;
            return;
        }
    }

    std::sort(arr, arr + 420);
    for (int i = 0; i < 420; i++) {
        std::print("{} ", arr[i]);
    }
    delete[] arr;
}

// resource acquisition is initialization
template <typename T>
class ArrayManager {
  public:
    ArrayManager(T* arr) : m_arr{arr} {
    }
    virtual ~ArrayManager() {
        delete[] m_arr;
    }
    T& operator[](int x) {
        return m_arr[x];
    }
    T* raw() {
        return m_arr;
    }

  private:
    T* m_arr;
};

void print_sorted_v2() {
    ArrayManager<short> arr{new short[420]};
    // short arr[420];
    for (int i = 0; i < 420; i++) {
        std::cin >> arr[i];
        if (arr[i] <= 0) {
            return;
        }
    }

    std::sort(arr.raw(), arr.raw() + 420);
    for (int i = 0; i < 420; i++) {
        std::print("{} ", arr[i]);
    }
}

template <typename T>
class ResourceManager {
  public:
    ResourceManager(T* ptr) : m_ptr{ptr} {
    }
    ~ResourceManager() {
        delete m_ptr;
    }
    T& operator*() {
        return *m_ptr;
    }
    T* operator->() {
        return m_ptr;
    }

  private:
    T* m_ptr;
};

void print_name(std::shared_ptr<Product> apple) {
    std::println("{} eyes on the {}", apple.use_count(), apple->name());
}

int main() {
    std::println("{}", factorial(10));
    std::println("{}", sizeof(unsigned long));
    print_sorted();
    print_sorted_v2();

    std::unique_ptr<Product> res{new Product};
    res->set_name("Red apple");
    std::println("{}", res->name());

    // release the ownership
    // Product* p = res.release();

    // get underlying object without releasing the ownership
    Product* p = res.get();
    std::println("{}", p->name());

    std::shared_ptr<Product> green{new Product};
    green->set_name("Green apple");
    std::println("before, count: {}", green.use_count());
    print_name(green);
    std::println("after, count: {}", green.use_count());
    green->set_price(0.42);
    std::println("{}", green->price());

    std::shared_ptr<short[]> sh_arr{new short[42]};
    sh_arr[11] = 44;

    std::allocator<int> IntAlloc;
    int* ptr = IntAlloc.allocate(5);
    std::allocator_traits<decltype(IntAlloc)>::construct(IntAlloc, ptr + 1, 42);
    std::println("{}, {}", *(ptr), *(ptr + 1));
    IntAlloc.deallocate(ptr, 5);

    return 0;
}
