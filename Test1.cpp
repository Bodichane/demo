#include <iostream>
#include <sstream>
#include <initializer_list>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    DoublyLinkedList(const std::initializer_list<T>& values) : DoublyLinkedList() {
        for (const T& value : values) {
            insert(value);
        }
    }

    DoublyLinkedList(const DoublyLinkedList& other) : DoublyLinkedList() {
        Node* curr = other.head;
        while (curr != nullptr) {
            insert(curr->data);
            curr = curr->next;
        }
    }

    DoublyLinkedList(DoublyLinkedList&& other) : DoublyLinkedList() {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
    }

    ~DoublyLinkedList() {
        while (!empty()) {
            remove(head->data);
        }
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            DoublyLinkedList tmp(other);
            std::swap(head, tmp.head);
            std::swap(tail, tmp.tail);
        }
        return *this;
    }

    DoublyLinkedList& operator=(DoublyLinkedList&& other) {
        if (this != &other) {
            std::swap(head, other.head);
            std::swap(tail, other.tail);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) {
        os << "[";
        Node* curr = list.head;
        while (curr != nullptr) {
            os << curr->data;
            curr = curr->next;
            if (curr != nullptr) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    void insert(const T& data) {
        Node* node = new Node{data, nullptr, nullptr};
        if (empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        tail->next = head;
        head->prev = tail;
    }

    void remove(const T& data) {
        Node* curr = head;
        while (curr != nullptr && curr->data != data) {
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (curr == head) {
                head = head->next;
            }
            if (curr == tail) {
                tail = tail->prev;
            }
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            delete curr;
            tail->next = head;
            head->prev = tail;
        }
    }

    bool contains(const T& data) const {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == data) {
                return true;
            }
            curr = curr->next;
            if (curr == head) {
                break;
            }
        }
        return false;
    }

    bool empty() const {
        return head == nullptr;
    }
};
