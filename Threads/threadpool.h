#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <mutex>
#include <queue>
#include <thread>

class ThreadPool {
  public:
    ThreadPool(int number_of_threads = 1000);
    std::thread get_free_thread();
    void push_thread(std::thread t);

  private:
    std::queue<std::thread> m_pool;
    std::mutex m_mutex;
};

#endif  // THREADPOOL_H
