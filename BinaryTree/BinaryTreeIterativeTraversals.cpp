#include <iostream>

using namespace std;


class TreeNode{
    public:
        int data;
        TreeNode *leftChild;
        TreeNode *rightChild;
        TreeNode(int d)
        {
            data = d;
            leftChild = nullptr;
            rightChild = nullptr;
        }
};

class QueueNode{
    public:
        TreeNode *tNodePtr;
        QueueNode *next;
        QueueNode(TreeNode *tNode)
        {
            tNodePtr = tNode;
            next = nullptr;
        }
};
class Queue{

    private:
        QueueNode *front;
        QueueNode *rear;
        int size = 0;
    public:
        Queue()
        {
            front = rear = nullptr;
        }
        
        int IsEmpty() 
        {
            if(front == nullptr)
                return 1;
            else
                return 0;

        }

        void Enqueue(TreeNode *tNode)
        {
            QueueNode *temp = new QueueNode(tNode);
            if(front == nullptr) front = temp;
            if( rear != nullptr)
            {
                //Set current rear nodes's next to newly created node.
                rear->next = temp;
            }
            rear = temp;
            size++;
        }

        TreeNode* Dequeue()
        {
            if(IsEmpty())
            {
                cout << "Queue is empty!" << endl;
                return nullptr;
            }
            TreeNode* data = front -> tNodePtr;
            QueueNode *temp = front;
            //When 1 element is left in queue and about to be deleted, reset rear pointer.
            if(front == rear)
                rear = nullptr;
            front = front -> next;
            delete temp;
            size--;
            return data;
        }

        void Display()
        {
            QueueNode *node = front;
            while(node != nullptr)
            {
                cout << node->tNodePtr->data << " ";
                node = node -> next;
            }
            cout << endl;
        }

        ~Queue()
        {
            QueueNode *node = front;
            while(node != nullptr)
            {
                QueueNode *temp = node;
                node = node -> next;
                delete temp;
            }
        }
};

struct StackNode {
    TreeNode *tNodePtr;
    struct StackNode *next;
    StackNode(TreeNode *tNode){
        tNodePtr = tNode;
        next = nullptr;
    }
    StackNode(){
    }
};

class Stack {
    public:
    StackNode* top = nullptr;
    bool isFull = false;
    Stack(){
    }

    int IsEmpty(){
        if(top == nullptr)
        {
            //cout << "Stack is empty." << endl;
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

    void Push(TreeNode *tNodePtr){
        StackNode *tmp = new StackNode(tNodePtr);
        if(tmp == nullptr){
            cout<<"Stack Overflow, Unable to crate new node on heap as heap memory is full." << endl;
            isFull = true;
            return;
        }
        tmp->next = top;    //Assign top node to newly created node's next address and move top to new node.
        top = tmp;
    }

    //After popping an element make sure to delete the top node.
    TreeNode* Pop(){
        TreeNode *tNode = nullptr;
        if(!IsEmpty()){
            StackNode *tmp = top;
            tNode = top->tNodePtr;
            top = top->next;
            delete tmp;
        }
        return tNode;
    }

    //Returns element at given position
    TreeNode* Peek(int position = 0){
        StackNode *tmp = top;
        for(int i=1; tmp != nullptr && i<position; i++){
            tmp = tmp-> next;
        }
        if(tmp != nullptr){
            return tmp->tNodePtr;
        }
        else{
            cout << "Couldnt find element at position : " << position << endl;
            return nullptr;
        }

    }
    void Display(){
        if(!IsEmpty()){        
            StackNode *tmp = top;
            while(tmp != nullptr){
                cout << tmp->tNodePtr << endl;
                tmp=tmp->next;
            }
        }
    }
};

void PreOrderTraversal(TreeNode *tNode){
    //Visit Node, Push it on stack, go to left child.
    //If node is null, pop from stack, go to right child. Continue until stack is empty or node is null. 
    Stack tNodeStack;
    while(!tNodeStack.IsEmpty() || tNode != nullptr)
    {
        if(tNode != nullptr){
            cout << tNode->data << endl;
            tNodeStack.Push(tNode);
            tNode = tNode->leftChild;
        }
        else {
            tNodeStack.Display();
            tNode = tNodeStack.Pop();
            tNode = tNode->rightChild;
        }

    }
}

void InorderTraversal(TreeNode *tNode){

    Stack tNodeStack;
    while(!tNodeStack.IsEmpty() || tNode != nullptr)
    {
        if(tNode != nullptr){
            tNodeStack.Push(tNode);
            tNode = tNode->leftChild;
        }
        else {
            tNode = tNodeStack.Pop();
            cout << tNode->data << endl;
            tNode = tNode->rightChild;
        }

    }
}

void PostOrderTraversal(TreeNode *tNode){

    Stack tNodeStack;
    TreeNode *prev = nullptr;
    while(!tNodeStack.IsEmpty() || tNode != nullptr)
    {
        if(tNode != nullptr)
        {
            tNodeStack.Push(tNode);
            prev = tNode;
            tNode = tNode -> leftChild;
        }
        else{
            tNode = tNodeStack.Peek(); //Just check top of stack/parent node to see if it has right child.

            if(tNode -> rightChild == nullptr || tNode -> rightChild == prev) //When right child is null or we already visited right child/subtree.
            {
                cout << tNode->data << endl;
                prev = tNode;
                tNodeStack.Pop();
                tNode = nullptr; //Make root pointer null to avoid visiting left subtree again.
            }
            else
            {
                tNode = tNode -> rightChild; //Traverse right subtree.
            }
            
        }
    }
}

void LevelOrderTraversal(TreeNode *tNode){
    Queue tNodeQueue;
    tNodeQueue.Enqueue(tNode);
    cout << tNode->data << endl;
    while(!tNodeQueue.IsEmpty())
    {
        tNode = tNodeQueue.Dequeue();
        if(tNode -> leftChild){
            cout << tNode -> leftChild -> data << endl;
            tNodeQueue.Enqueue(tNode->leftChild);
        }
        if(tNode -> rightChild){
            cout << tNode -> rightChild -> data << endl;
            tNodeQueue.Enqueue(tNode->rightChild);
        }
    }
}

int main()
{
    Queue tNodeQueue;
    cout << "Enter root node data : " << endl;
    TreeNode *root=nullptr, *ptr=nullptr;
    int data;
    cin >> data;
    if(data != -1)
    {
        root = new TreeNode(data);
        tNodeQueue.Enqueue(root);
    }
    while (!tNodeQueue.IsEmpty())
    {
        ptr = tNodeQueue.Dequeue();
        if(ptr != nullptr){
            int data = 0;
            cout << "Enter left child of " << ptr->data << endl;
            cin >> data;
            if(data != -1){
                TreeNode *tmp = new TreeNode(data);
                ptr->leftChild = tmp;
                tNodeQueue.Enqueue(tmp);
            }
            cout << "Enter right child of " << ptr->data << endl;
            cin >> data;
            if(data != -1){
                TreeNode *tmp = new TreeNode(data);
                ptr->rightChild = tmp;
                tNodeQueue.Enqueue(tmp);
            }
        }
    }
    
    cout << "Preorder Traveral: " << endl;
    PreOrderTraversal(root);
    cout << "Inorder Traveral: " << endl;
    InorderTraversal(root);
    cout << "Postorder Traveral: " << endl;
    PostOrderTraversal(root);
    cout << "Level Order Traversal " << endl;
    LevelOrderTraversal(root);

    return 0;
}