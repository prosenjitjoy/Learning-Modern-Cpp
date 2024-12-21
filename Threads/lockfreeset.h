#ifndef LOCKFREESET_H
#define LOCKFREESET_H

#include <atomic>

template <typename T>
class LockFreeSet {
  public:
    LockFreeSet() : head{nullptr} {
    }

    bool insert(const T& value) {
        Node* newNode = new Node(value);
        while (true) {
            Node* curHead = head.load();
            newNode->next = curHead;
            if (head.compare_exchange_weak(curHead, newNode)) {
                return true;
            }
            newNode->next = nullptr;
        }
    }

    bool contains(const T& value) {
        Node* curNode = head.load();
        while (curNode != nullptr) {
            if (curNode->value == value) {
                return true;
            }
            curNode = curNode->next;
        }

        return false;
    }

  private:
    struct Node {
        T value;
        Node* next;
        Node(const T& v) : value{v}, next{nullptr} {
        }
    };

    std::atomic<Node*> head;
};

#endif  // LOCKFREESET_H
