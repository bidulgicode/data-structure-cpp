/**
 * Array Based stack
 */

#include <iostream>
#define MAX_SIZE 50
using namespace std;

template <typename T> 
class Stack {
    private:
        T *values;
        int top;

        bool isFull(){
            if(top >= MAX_SIZE-1)
                return true;
            else
                return false;
        }

    public:
        Stack(){
            values = new T[MAX_SIZE];            
            top = -1;
        }
        
        ~Stack(){
            
        }

        T peek(){
            if(isEmpty()){
                cout << "Stack is empty \n";
                exit(EXIT_FAILURE);
            }

            return values[top];
        }

        void push(T item){
            if(isFull()){
                cout << "Stack is full \n";
                return;
            }

            top++;
            values[top] = item;
        }

        T pop(){
            if(isEmpty()){
                cout << "Stack is empty \n";
                return NULL;
            }

            T item = values[top];
            top--;
            return item;
        }

        void Clear(){
            if(isEmpty()){
                cout << "Stack is empty \n";
                return;
            }

            top = -1;
            cout << "Stack cleared \n";
        }
        
        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }
};