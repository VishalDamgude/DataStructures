#include <iostream>

using namespace std;


//Stack using linked list. We will add/remove node to/from list at head position to get O(1) stack opeartions.
struct StackNode {
    int data;
    struct StackNode *next;
    StackNode(int d){
        data = d;
        next = nullptr;
    }
    StackNode(){

    }
};

class Stack {
    public:
    //StackNode *head = nullptr;
    StackNode* top = nullptr;
    bool isFull = false;
    Stack(){
    }

    int IsEmpty(){
        if(top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return 1;
        }
        return 0;
    }

    bool IsFull() {
        StackNode *tmp = new StackNode();
        if(tmp == nullptr){
            cout<<"Stack Overflow, Unable to crate new node on heap as heap memory is full." << endl;
            isFull = true;
        }
        delete tmp;
        return isFull;
    }

    void Push(int d){
        StackNode *tmp = new StackNode(d);
        if(tmp == nullptr){
            cout<<"Stack Overflow, Unable to crate new node on heap as heap memory is full." << endl;
            isFull = true;
            return;
        }
        tmp->next = top;    //Assign top node to newly created node's next address and move top to new node.
        top = tmp;
    }

    //After popping an element make sure to delete the top node.
    int Pop(){
        int d = -1;
        if(!IsEmpty()){
            StackNode *tmp = top;
            d = top-> data;
            top = top->next;
            delete tmp;
        }
        return d;
    }

    //Returns element at given position
    int Peek(int position){
        StackNode *tmp = top;
        for(int i=1; tmp != nullptr && i<position; i++){
            tmp = tmp-> next;
        }
        if(tmp != nullptr){
            return tmp->data;
        }
        else{
            cout << "Couldnt find element at position : " << position << endl;
            return -1;
        }

    }
    void Display(){
        if(!IsEmpty()){        
            StackNode *tmp = top;
            while(tmp != nullptr){
                cout << tmp->data << endl;
                tmp=tmp->next;
            }
        }
    }
};

int main() {

    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
    int d;
    cout << "Popping : " << endl;
    d = s.Pop();
    d = s.Pop();
    d = s.Pop();
    d = s.Pop();
    s.Display();
    cout << "Pushing: " << endl;
    s.Push(40);
    s.Display();
    d = s.Peek(3);
    s.Push(50);
    s.Push(60);
    s.Push(70);
    s.Display();
    d=s.Peek(3);
    cout << "Element at position 3: " << d << endl;
    return 0;
}