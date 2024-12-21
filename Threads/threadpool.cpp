#include "threadpool.h"

#include <stdexcept>

ThreadPool::ThreadPool(int number_of_threads) {
    for (int ix = 0; ix < number_of_threads; ix++) {
        m_pool.push(std::thread());
    }
}

std::thread ThreadPool::get_free_thread() {
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_pool.empty()) {
        throw std::range_error("no available thread");
    }
    auto t = std::move(m_pool.front());
    m_pool.pop();
    return t;
}

void ThreadPool::push_thread(std::thread t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_pool.push(std::move(t));
}
