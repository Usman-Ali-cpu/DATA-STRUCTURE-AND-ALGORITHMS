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

class LinkList{
    Node *head;
public:
    LinkList(){
        head = NULL;
    }
    void insert(int x){
        if(head == NULL){
            head = new Node(x);
        }
        else {
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }
    int remove(){
        if(head== NULL){
            return -2334;
        }
        if(head->next == NULL){
            int x = head->x;
            head = NULL;
            return x;
        }
        else {
            Node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            int x = temp->next->x;
            temp->next = NULL;
            return x;
        }
    }
    int removeAt(int n){
        Node *temp = head;
        Node *previous = NULL;
        for (int i = 0; i < n; i++){
            previous = temp;
            temp = temp->next;
        }
        if(temp== head){
            int y = removeAtStart();
            return y;
        }else {
            int x = temp->x;
            previous->next = temp->next;
            delete temp;
            return x;
        }
    }
    void insertAt(int n, int val){
        Node *temp = head;
        Node *t = new Node(val);
        Node *previous = NULL;
        for (int i = 0; i < n; i++){
            previous = temp;
            temp = temp->next;
        }
        if(temp==head){
            insertAtStart(val);
        }
        else
        previous->next = t;
        t->next = temp;
    }
    bool isEmpty(){
        return head == NULL;
    }
    void insertAtStart(int x){
        if(head == NULL){
            head = new Node(x);
        }
        else{
            Node *temp = new Node(x);
            temp->next = head;
            head = temp;
        }
    }
    int removeAtStart(){
        if(head == NULL){
            return -1344;
        }
        if(head->next == NULL){
            int c = head->x;
            head = NULL;
            return c;
        }
        else {
            int x = head->x;
            Node *temp = head;
            head = head->next;
            delete temp;
            return x;
        }
    }
    void show(){
        Node *temp = head;
        while(temp != NULL){
            cout << "Value: " << temp->x << endl;
            temp = temp->next;
        }
    }
    ~LinkList(){
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
    // LinkList li;
    // li.insert(4);
    // li.insert(3);
    // li.insert(6);
    // li.insert(9);
    // li.insertAtStart(20);
    // li.insert(1);
    // li.insertAt(5, 10);
    // li.removeAt(4);
    // cout << li.remove() << endl;
    // cout << li.removeAtStart() << endl;
    // li.show();

    return 0;
}