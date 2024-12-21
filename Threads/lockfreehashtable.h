#ifndef LOCKFREEHASHTABLE_H
#define LOCKFREEHASHTABLE_H

#include <atomic>
#include <functional>

template <typename K, typename V, std::size_t N>
class LockFreeHashtable {
  public:
    LockFreeHashtable() {
        for (std::size_t i = 0; i < N; i++) {
            buckets[i].store(nullptr);
        }
    }

    bool insert(const K& key, const V& value) {
        std::size_t hash = std::hash<K>()(key) % N;
        Node* newNode = new Node(key, value);
        while (true) {
            Node* head = buckets[hash].load();
            newNode->next = head;
            if (buckets[hash].compare_exchange_weak(head, newNode)) {
                return true;
            }

            // if compare_exchange_weak fails, head is
            // updated to the new value.
            // we need to update the next pointer of
            // newNode and try again
            newNode->next = nullptr;
        }
    }

    bool find(const K& key, V& value) {
        std::size_t hash = std::hash<K>()(key) % N;
        Node* node = buckets[hash].load();
        while (node != nullptr) {
            if (node->key == key) {
                value = node->value;
                return true;
            }
            node = node->next;
        }
        return false;
    }

  private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v) : key{k}, value{v}, next{nullptr} {
        }
    };

    std::atomic<Node*> buckets[N];
};

#endif  // LOCKFREEHASHTABLE_H
