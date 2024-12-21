#include "safestack.h"

template <typename T>
SafeStack<T>::SafeStack(const SafeStack &other) {
    std::lock_guard<std::mutex> lock(other.m_mutex);
    m_wrappee = other.m_wrappee;
}

template <typename T>
void SafeStack<T>::push(T value) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_wrappee.push(value);
}

template <typename T>
std::shared_ptr<T> SafeStack<T>::pop() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_wrappee.empty()) {
        return nullptr;
    } else {
        return std::make_shared<T>(m_wrappee.top());
    }
}

template <typename T>
bool SafeStack<T>::empty() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_wrappee.empty();
}
