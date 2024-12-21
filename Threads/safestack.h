#ifndef SAFESTACK_H
#define SAFESTACK_H

#include <memory>
#include <mutex>
#include <stack>

template <typename T>
class SafeStack {
  public:
    SafeStack() = default;
    SafeStack(const SafeStack& other);
    void push(T value);
    std::shared_ptr<T> pop();
    bool empty() const;

  private:
    std::stack<T> m_wrappee;
    mutable std::mutex m_mutex;
};

#endif  // SAFESTACK_H
