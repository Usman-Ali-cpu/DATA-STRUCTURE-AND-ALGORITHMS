#include <iostream>
using namespace std;

int S = 5;
class Node{
public:
    int x;
    Node *left;
    Node *right;
    Node(){
        x = 0;
        left = NULL;
        right = NULL;
    }
    Node (int v){
        x = v;
        left = NULL;
        right = NULL;
    }
};

class BST{
    Node *root;
public:
    BST(){
        root = NULL;
    }

    bool isTreeEmpty(){
        return (root == NULL);
    }
    void insertTree(int n){
        Node *insert = new Node(n);
        if(root == NULL){
            root = insert;
            cout << "Inserted Root\n";
        }
        else 
        {
            Node *temp = root;
            while(temp != NULL)
            {
                if(insert->x == temp->x){
                    return;
                }
                else if(insert->x < temp->x  && temp->left == NULL){
                    temp->left = insert;
                    cout << temp->left->x;
                    cout << " Inserted left \n";
                    break;
                }
                else if(insert->x < temp->x ){
                    temp = temp->left;
                }
                else if(insert->x > temp->x  && temp->right == NULL){
                    temp->right = insert;
                    cout << temp->right->x;
                    cout << " Inserted Right\n";
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
    void preOrder(){
        Node *tmep = root;
        cout << "PreOrder : ";
        printPreOrder(tmep);
        cout << endl;
    }
    void postOrder(){
        Node *tmep = root;
        cout << "Post Order : ";
        printPostOrder(tmep);
        cout << endl;
    }
    void inOrder(){
        cout << "In Order : ";
        Node *tmep = root;
        printInOrder(tmep);
        cout << endl;
    }
    void D2(){
        Node *temp = root;
        print2D(temp, 3);
    }
    Node * search(int val){
        searchNode(root, val);
    }
    // NLR
    void printPreOrder(Node * temp){
        if( temp == NULL){
            return;
        }
        cout << temp->x << " ";
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
    // LRN
    void printPostOrder(Node *temp){
        if( temp == NULL){
            return;
        }
        
        printPostOrder(temp->left);
        printPostOrder(temp->right);
        cout << temp->x << " ";
    }
    // LNR
    void printInOrder(Node *temp){
        if( temp == NULL){
            return;
        }
        printInOrder(temp->left);
        cout << temp->x << " ";
        printInOrder(temp->right);
    }
    void print2D(Node *temp, int space){
        if(temp == NULL){
            return;
        }
            space = space + S;
            print2D(temp->right, space);
            cout<< endl;
            for (int i = S; i < space; i++){
                cout << " ";
            }
            cout << temp->x << endl;
            print2D(temp->left, space);
    }

    void printLevelOrder(Node *root);

    Node *searchNode(Node *temp, int v){
        if(root== NULL){
            return root;
        }
        else 
        {
            Node *t = root;
            while(t != NULL){
                if(t->x = v){
                    return t;
                }
                else if(t->x < v){
                    t = t->left;
                }
                else{
                    t = t->right;
                }
            }
            return NULL;
        }
    }
    Node * getroot(){
        return root;
    }
    int getHeight(){
        Node *t = root;
        int h = height(t);
    }
    int height(Node * t){
        if(t == NULL){
            return -1;
        }
        else 
        {
            int leftH = height(t->left);
            int rightH = height(t->right);
            if(leftH > rightH){
                return leftH+1;
            }
            else {
                return rightH + 1;
            }
        }
        return 0;
    }
    void PrintLevelOrder(){
        cout << "Level Order : ";
        int h = height(root);
        for (int i = 0; i <= h; i++){
            givenLevel(root, i);
        }
        cout << endl;
    }
    void givenLevel(Node * t, int l){
        if (t== NULL){
            return;
        }
        else if(l == 0){
            cout << t->x << " ";
        }
        else {
            givenLevel(t->left, l - 1);
            givenLevel(t->right, l - 1);
        }
    }



    Node *minValNode(Node *node){
        Node *temp = node;
        while(temp->left !=NULL){
            temp = temp->left;
        }
        return temp;
    }
    Node *deleteNode(Node *node, int v){
        if(root == NULL){
            return NULL;
        }
        else if(v < node->x ){
            node->left = deleteNode(node->left, v);
        }
        else if(v > node->x ){
            node->right = deleteNode(node->right, v);
        }
        else 
        {
            if(node->left == NULL){
                Node * temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node *temp = minValNode(node->right);
                node->x = temp->x;
                node->right = deleteNode(node->right, temp->x);
            }
        }
        return node;
    }

};


int main(){
    BST b;
    if(b.isTreeEmpty()){
        cout << "Tree Empty "<< endl;
    }
    else {
        cout << "Tree Not Empty " << endl;
    }
    b.insertTree(22); // root
    b.insertTree(45); // right
    b.insertTree(12); // left 
    b.insertTree(20); // right
    b.insertTree(50); // root
    b.insertTree(40); // right
    b.insertTree(60); // left 
    b.insertTree(2); // right
    b.preOrder();
    b.postOrder();
    b.inOrder();
    b.PrintLevelOrder();
    b.deleteNode(b.getroot(), 12);
    b.preOrder();

    // b.D2();
    // Node * t= b.search(60);
    // cout << "value : " << t->x << endl;
    // Node *temp = b.getroot();
    // cout << "Height of Tree : " << b.height(temp) << endl;

    // cout << endl;
    // cout << endl;
    // cout << endl;

    /*
    int option;
    do {
        cout<< "What is operation do you want to perform ? "<< endl;
        cout<< "Select Option number. Enter 0 to exit"<< endl;
        cout<<  "1. Insert "<< endl;
        cout << "2. Search " << endl;
        cout << "3. Delete " << endl;
        cout << "4. Print " << endl;
        cout << "5. Clear Screen " << endl;
        cout << "0. Exit " << endl;
        cout << "Enter : ";
        cin >> option;
        switch (option)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            system("cls");
            break;
        case 0:
            
            break;
        default:
            cout << "Invalid Option "<< endl;
            break;
        }

    }while(option != 0);

*/

    return 0;
}