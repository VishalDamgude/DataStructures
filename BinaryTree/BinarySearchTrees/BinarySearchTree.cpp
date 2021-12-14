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

//Insertion Time Complexity for inserting 1 node = O(log n) as we need to search a position of node in BST.
TreeNode* Insert_Recurse(TreeNode *root, int key){
    if(root == nullptr)
    {
        //Key not present in tree, create new node with key.
        root = new TreeNode(key);
        return root;
    }
    if(key < root->data)
    {
        root->leftChild = Insert_Recurse(root->leftChild, key);
    }
    else if (key > root->data)
    {
        root->rightChild = Insert_Recurse(root->rightChild, key);
    }
    return root;
}

//Insertion Time Complexity for inserting 1 node = O(log n), For inserting n nodes, it will be O(n*log n).
void Insert(TreeNode *root, int key)
{
    TreeNode* parent = nullptr;
    while(root != nullptr)
    {
        parent = root;
        if(key == root->data)
        {
            cout << "Key: " << key << " already present, can't have duplicate node in BST" << endl;
            return;
        }
        if(key < root->data)
            root = root -> leftChild;
        else
            root = root->rightChild;
    }
    root = new TreeNode(key);
    if(parent != nullptr)
    {
        if(key < parent->data)
            parent->leftChild = root;
        else
            parent->rightChild = root;
    }
}

//Iterative search in BST
TreeNode* Search(TreeNode* tNode, int key)
{
    while(tNode != NULL)
    {
        if(key == tNode->data)
            return tNode;
        if(key < tNode -> data)
        {
            tNode = tNode->leftChild;
        }
        else
            tNode = tNode->rightChild;
    }
    return tNode;
}

TreeNode* SearchRescurse(TreeNode* tNode, int key)
{
    //if(tNode == nullptr)
    //    return nullptr;
    if(tNode == nullptr || key == tNode->data)
        return tNode;
    if(key<tNode->data)
        return SearchRescurse(tNode->leftChild, key);
    else
        return SearchRescurse(tNode->rightChild, key);
}

void Inorder(TreeNode* tNode)
{
    if(tNode == nullptr)
        return;
    Inorder(tNode->leftChild);
    cout << tNode->data << " " << endl;
    Inorder(tNode->rightChild);
}

int Height(TreeNode *tNode)
{
    if(tNode == nullptr)
        return -1;
    int leftHeight = Height(tNode->leftChild);
    int rightHeight = Height(tNode->rightChild);
    if( leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}

TreeNode* InorderPredecessor(TreeNode *tNode)
{
    if(tNode == nullptr)
        return nullptr;
    TreeNode* tmp = tNode->leftChild;
    while(tmp && tmp->rightChild)
    {
        tmp = tmp->rightChild;
    }
    return tmp;
}

TreeNode* InorderSuccessor(TreeNode *tNode)
{
    if(tNode == nullptr)
        return nullptr;
    TreeNode* tmp = tNode->rightChild;
    while(tmp && tmp->leftChild)
    {
        tmp = tmp->leftChild;
    }
    return tmp;
}

TreeNode* Delete(TreeNode* root, int key)
{
    if(root == nullptr)
        return root;
   
    if(root->data == key)
    {
         //Node to be deleted is a leaf node
        if(root->leftChild == nullptr && root->rightChild == nullptr)
        {
            delete root;
            root = nullptr;
            return root;
        } else {
            //TODO: Node to be deleted has at least one child (left/right).
            /*This node needs to replaced by one of the nodes from left/right subtrees.
            Check height of its left and right subtrees.
            If Height(LeftSubtree) > Height(RightSubtree), pick replacement node from left subtree. i.e. select inorder predecessor.
            else select inorder successor.
            */
           if(Height(root->leftChild) > Height(root->rightChild))
           {
               TreeNode* inPredecessor = InorderPredecessor(root);
               //Assign data from in_predecessor node to current node(to be deleted) and then delete the inorder predecessor.
               root->data = inPredecessor->data;
               root->leftChild = Delete(root->leftChild, inPredecessor->data);
           }
           else
           {
               TreeNode* inSuccessor = InorderSuccessor(root);
               //Assign data from inSuccessor node to current node(to be deleted) and then delete the inorder successor.
               root->data = inSuccessor->data;
               root->rightChild = Delete(root->rightChild, inSuccessor->data);
           }

        }
    }
    if(key < root->data)
    {
        //Search in left subtree.
        root->leftChild = Delete(root->leftChild, key);
    } else {
        //Search in right subtree.
        root->rightChild = Delete(root->rightChild, key);
    }
    return root;
}

int main(){

    TreeNode *root = nullptr;
    int input[] = {50, 40, 45, 50, 90, 75, 25, 60, 30, 70};
    int len = sizeof(input)/sizeof(input[0]);
    /*for(int i=0; i<len; i++)
    {
        root = Insert_Recurse(root, input[i]);
    }*/
    root = new TreeNode(input[0]);
    for(int i=1; i<len; i++)
    {   
        Insert(root, input[i]);
    }
    Inorder(root);
    TreeNode* tmp = nullptr;
    tmp = Search(root, 50);
    if(tmp != nullptr)
        cout << "Key " << tmp->data << " found." << endl;
    else
        cout << "Key 50 not found." << endl;
    
    tmp = Search(root, 56);
    if(tmp != nullptr)
        cout << "Key " << tmp->data << " found." << endl;
    else
        cout << "Key 56 not found." << endl;

    
    tmp = SearchRescurse(root, 70);
    if(tmp != nullptr)
        cout << "Key " << tmp->data << " found." << endl;
    else
        cout << "Key 70 not found." << endl;

    tmp = SearchRescurse(root, 71);
    if(tmp != nullptr)
        cout << "Key " << tmp->data << " found." << endl;
    else
        cout << "Key 71 not found." << endl;

    cout << "Height of BST is: " << Height(root) << endl;

    Delete(root, 70);
    cout << "After deleting Node 70: Height=" << Height(root) << endl;
    Inorder(root);
    Delete(root,50);
    cout << "After deleting Node 50 (root Node), Height = "<< Height(root) << endl;
    Inorder(root);
    return 0;
}
