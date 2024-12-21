#include <atomic>
#include <chrono>
#include <future>
#include <mutex>
#include <print>
#include <thread>
#include <vector>

#include "lockfreehashtable.h"
#include "lockfreequeue.h"
#include "lockfreeset.h"

void print_numbers_in_background() {
    // for (int ix = 0; ix < 100000; ix++) {
    //     std::println("Background: {}", ix++);
    // }

    int ix{0};
    while (true) {
        std::println("Background: {}", ix++);
    }
}

class TestTask {
  public:
    TestTask() = default;
    void operator()() {
        ++m_state;
        std::println("value of state: {}", m_state);
    }

  private:
    int m_state = 0;
};

void foo(int a, int b) {
    std::println("{} + {} = {}", a, b, a + b);
}

int global = 0;
std::mutex locker;
void inc() {
    // locker.lock();
    std::lock_guard g(locker);
    global++;
    // locker.unlock();
}

class MySingleton {
  public:
    static std::shared_ptr<MySingleton> get_instance() {
        // double checking locking pattern
        if (m_instance == nullptr) {
            std::lock_guard lg(m_mutex);
            if (m_instance == nullptr) {
                m_instance = std::make_shared<MySingleton>();
            }
        }
        return m_instance;
    }

  private:
    inline static std::mutex m_mutex;
    inline static std::shared_ptr<MySingleton> m_instance = nullptr;
    // inline static MySingleton* m_instance = nullptr;
};

void create_something_unique() {
    std::shared_ptr<MySingleton> inst = MySingleton::get_instance();
    // do something useful
}

void create_something_useful() {
    std::shared_ptr<MySingleton> anotherInst = MySingleton::get_instance();
    // do something unique
}

std::future<int> long_running_task() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return std::async(std::launch::async, []() { return 42; });
}

int count = 0;
std::mutex m;
void counter() {
    std::lock_guard g{m};
    count++;
}

void function() {
    std::atomic_int i;
    i.store(1);
    std::println("{}", i.load());
}

int main() {
    // std::thread background{print_numbers_in_background};
    // for (int jx = 0; jx < 100000; jx++) {
    //     std::println("Main: {}", jx++);
    // }
    // background.join();

    std::thread t1{[]() { std::println("A lambda passed to the thread"); }};
    t1.join();
    std::thread t2{TestTask()};
    t2.join();

    std::jthread jt{TestTask()};

    // std::jthread jbackground{print_numbers_in_background};
    // for (int jx = 0; jx < 100000; jx++) {
    //     std::println("Main: {}", jx++);
    // }
    // // The main thread is about to finish, so we request the background
    // thread
    // // to stop
    // jbackground.request_stop();

    std::jthread t3{foo, 4, 2};

    // thread pool
    std::vector<std::thread> pool;

    std::jthread t4{inc};
    std::thread t5{inc};
    t5.join();
    // std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::println("{}", global);

    std::jthread t6{create_something_unique};
    std::jthread t7{create_something_useful};

    // std::println("Starting the task...");
    // auto result = co_await long_running_task();
    // std::println("Task completed. Result: {}", result);

    std::jthread A{counter};
    std::jthread B{counter};
    std::jthread C{[] { counter(); }};
    std::thread D{[] {
        for (int i = 0; i < 10; i++) {
            counter();
        }
    }};
    D.join();
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::println("Count: {}", count);

    function();

    LockFreeQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    int value;
    while (q.pop(value)) {
        std::println("Poped value: {}", value);
    }

    LockFreeHashtable<int, std::string, 100> hashTable;
    hashTable.insert(1, "one");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");

    std::string val;
    if (hashTable.find(4, val)) {
        std::println("Found value: {}", val);
    } else {
        std::println("Value not found.");
    }

    LockFreeSet<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);

    if (set.contains(2)) {
        std::println("Set contains 2");
    } else {
        std::println("Set does not contain 2");
    }

    return 0;
}
