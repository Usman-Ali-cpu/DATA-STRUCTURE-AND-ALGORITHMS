#include <iostream>
using namespace std;

class Node {
public:
    int x;
    Node *next;
    Node(int x){
        this->x = x;
        next = NULL;
    }
    Node (){
        next = NULL;
    }
};

class LLStack{
    Node *head;
    int top;
public:
    LLStack(){
        top = -1;
        head = NULL;
    }
    void push(int val){
        if(head== NULL){
            head = new Node(val);
            top = 0;
        }
        else {
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new Node(val);
            ++top;
        }
    }
    int pop(){
        Node *temp = head;
        int x;
        if(temp== NULL){
            return -2234;
        }
        if(head->next == NULL){
            x = temp->x;
            head = NULL;
            top = -1;
            return x;
        }
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            x = temp->next->x;
            temp->next = NULL;
            return x;
        top--;
    }
    int peek(){
        Node *temp = head;
        int x;
        if(head== NULL){
            return -1234;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        x = temp->x;
        return x;
    }
    int peek2(){
        Node *temp = head;
        int x;
        if(head== NULL){
            return -1234;
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        x = temp->x;
        return x;
    }
    bool isEmpty(){
        return head == NULL;
    }
    void show(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->x << endl;
            temp = temp->next;
        }
    }
    ~LLStack(){
        Node *temp = head;
        while(temp!= NULL){
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        head = NULL;
    }

};


int main(){
    LLStack st;
    st.push(2);
    st.push(1);
    st.push(5);
    st.push(4);
    // st.show();
    // cout << st.pop() << endl;
    // cout << st.pop()<< endl;
    // cout << st.pop()<< endl;
    // cout << st.peek()<< endl;
    // cout << st.pop()<< endl;
    cout << st.peek()<< endl;
    cout << st.peek2() << endl;

    return 0;
}
