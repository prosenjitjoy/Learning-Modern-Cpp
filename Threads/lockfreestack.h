#ifndef LOCKFREESTACK_H
#define LOCKFREESTACK_H

#include <atomic>
#include <memory>

template <typename T>
class LockFreeStack {
  public:
    LockFreeStack() = default;

    void push(T data) {
        std::shared_ptr<node> new_elem = std::make_shared<node>(data);
        new_elem->next = m_head.load();
        while (!std::atomic_compare_exchange_weak(&m_head, &new_elem->next,
                                                  new_elem)) {
            new_elem->next = m_head.load();
        }
    }

    std::shared_ptr<T> pop() {
        std::shared_ptr<node> old_head = m_head.load();
        while (old_head && !std::atomic_compare_exchange_weak(
                               &m_head, &old_head, old_head->next)) {
            old_head = m_head.load();
        }

        return old_head ? std::make_shared<T>(std::move(old_head->value))
                        : nullptr;
    }

  private:
    struct node {
        T data;
        std::shared_ptr<node> next;
        node(T value) : data{std::move(value)}, next{nullptr} {
        }
    };

    std::atomic<std::shared_ptr<node>> m_head;
};

#endif  // LOCKFREESTACK_H
