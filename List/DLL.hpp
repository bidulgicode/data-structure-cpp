/**
 * Doubly LinkedList
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedList {
   private:
    class Node {
        friend class LinkedList;

       private:
        T data;
        class Node* next;
        class Node* prev;

       public:
        Node() {
            next = NULL;
            prev = NULL;
        }
        Node(T item, Node* _prev, Node* _next) {
            data = item;
            prev = _prev;
            next = _next;
        }
    };
    Node *head, *tail;
    int size;

   public:
    LinkedList();
    ~LinkedList();
    void add(T item);
    bool Remove(T item);
    T Find(T item);
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = new Node();
    tail = new Node();
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head->next != NULL) {
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    delete head;
}

template <typename T>
void LinkedList<T>::add(T item) {
    tail->prev->next = new Node(item, tail->prev, tail);
    search->next = search->next->prev;
    size++;
}

template <typename T>
bool LinkedList<T>::Remove(T item) {
    if (item == head) {
        head->next->prev = NULL;
        head = head->next;
        size--;
        return true;
    }

    Node* target = head;
    while (target->next != tail) {
        if (target->data == item) {
            target->prev->next = target->next->prev;
            size--;
            return true;
        }
    }
    return false;
}

template <typename T>
T LinkedList<T>::Find(T item) {
    Node* target = head;
    while (target->next != tail) {
        if (target->data == item)
            return target;
        target = target->next;
    }
    return NULL;
}