#include <iostream>
#include <vector>
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

void PreOrderTraversal(TreeNode *tNode){
    if (tNode == nullptr)
        return;
    cout << tNode -> data << endl;
    PreOrderTraversal(tNode->leftChild);
    PreOrderTraversal(tNode->rightChild);
}

void IterativePreorderTraversal(TreeNode *tNode){

}

void InorderTraversal(TreeNode *tNode){
    if(tNode == nullptr)
        return;
    InorderTraversal(tNode->leftChild);
    cout << tNode->data << endl;
    InorderTraversal(tNode->rightChild);
}

void PostOrderTraversal(TreeNode *tNode){
    if(tNode == nullptr)
        return;
    PostOrderTraversal(tNode->leftChild);
    PostOrderTraversal(tNode->rightChild);
    cout << tNode -> data << endl;
}

//Most operations on Binary Trees follow Postorder Form i.e. left, right and then root
int CountNodes(TreeNode *tNode)
{
    if(tNode == nullptr)
        return 0;
    return 1 + CountNodes(tNode->leftChild) + CountNodes(tNode->rightChild);

}

int CountLeafNodes(TreeNode *tNode)
{
    if(tNode == nullptr)
        return 0;
    if(tNode->leftChild == nullptr && tNode->rightChild == nullptr)
        return 1;
    return CountLeafNodes(tNode->leftChild) + CountLeafNodes(tNode->rightChild);
}

int Height(TreeNode* tNode)
{
    if(tNode == nullptr)
        return -1;
    int leftHeight = Height(tNode->leftChild);
    int rightHeight = Height(tNode->rightChild);
    if(leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}
vector<int> search_path;

bool RootToNodePath(TreeNode* root, int data)
{
    //Go Inorder fashion until data is found.
    if(root == nullptr)
        return false;
    search_path.push_back(root->data);
    if(root->data == data)
        return true;
    bool isFoundLeft = RootToNodePath(root->leftChild, data);
    if(isFoundLeft)
        return true;

    bool isFoundRight = RootToNodePath(root->rightChild, data);
    if(isFoundRight)
        return true;

    //If data not dound in both left and right subtree then pop from vector.
    search_path.pop_back();
    return false;

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
    cout << "Inorder Traveral: " << endl;
    InorderTraversal(root);
    cout << "Preorder Traveral: " << endl;
    PreOrderTraversal(root);
    cout << "Postorder Traveral: " << endl;
    PostOrderTraversal(root);
    cout << "No. Of Nodes : " << CountNodes(root) << endl;
    cout << "No. of leaf nodes: " << CountLeafNodes(root) << endl;
    cout << "Height of Binary Tree: " << Height(root) << endl;
    cout << "Search Path to Node 80: " << RootToNodePath(root, 80) << endl;
    for (auto it = search_path.begin(); it != search_path.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
    search_path.clear();
    cout << "Search Path to Node 50: " << RootToNodePath(root, 50) << endl;
    for (auto it = search_path.begin(); it != search_path.end(); ++it)
        cout << ' ' << *it;
    cout << endl;

    return 0;
}