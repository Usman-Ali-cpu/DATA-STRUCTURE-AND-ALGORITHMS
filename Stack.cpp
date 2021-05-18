#include <iostream>
using namespace std;

template <class T>

class Stack{
    int top;
    int size;
    T *arr;
public:
    Stack(){
        top = -1;
        arr = new int[20];
    }
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[size];
    }
    void push(T x){
        if(!isFull()){
            arr[++top] = x;
        }
    }
    T pop(){
        if(!isEmpty()){
            return arr[top--];
        }
    }
    T getTop(){
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size - 1;
    }
    ~Stack(){
        delete[] arr;
        arr = NULL;
    }
};


int main(){
    Stack <int> s;
    s.push(2);
    s.push(3);
    cout << s.pop();

    return 0;
}