/**
 * List Based Queue
 */

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class Queue {
   private:
    class Node {
        friend class Queue;

       private:
        T data;
        Node* prev;
        Node* next;

       public:
        Node() {
            prev = NULL;
            next = NULL;
        }
        Node(T item, Node* _prev, Node* _next) : data(item), prev(_prev), next(_next) { }
    };

    Node* head;
    Node* tail;
    int size;
    
    public:
        Queue(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ~Queue(){
            while(head != NULL){
                Node* temp = head;
                head = temp->next;
                delete temp;
            }
        }
        
        bool empty(){
            return head == NULL;
        }
        void push(T item);
        T pop();
        T front();
        T back();
        int getSize();
};

template <typename T>
void Queue<T>::push(T item){
    tail = new Node(item, tail, NULL);

    if(empty()) 
        head = tail;
    else 
        tail->prev->next = tail;

    size++;
}

template <typename T>
T Queue<T>::pop(){
    if(empty())
        return NULL;
    
    Node* target = head;
    T item = target->data;

    head = target->next;
    
    if(head == NULL)
        tail = NULL;
    
    size--;
    delete target;

    return item;
}

template <typename T>
T Queue<T>::front(){
    if(empty())
        return NULL;

    return head->data;
}

template <typename T>
T Queue<T>::back(){
    if(empty())
        return NULL;
    
    return tail->data;
}

template <typename T>
int Queue<T>::getSize(){
    return size;
}