#include <iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        int height;
        TreeNode *leftChild;
        TreeNode *rightChild;
        TreeNode(int d)
        {
            data = d;
            height = 0;
            leftChild = nullptr;
            rightChild = nullptr;
        }
};

int BalanceFactor(TreeNode* root)
{
    int leftHeight = root->leftChild ? root->leftChild->height + 1 : 0;
    int rightHeight = root->rightChild ? root->rightChild->height + 1: 0;
    return leftHeight - rightHeight;
}

void Inorder(TreeNode* tNode)
{
    if(tNode == nullptr)
        return;
    Inorder(tNode->leftChild);
    printf("data: %d height: %d BF: %d\n", tNode->data, tNode->height, BalanceFactor(tNode));
    Inorder(tNode->rightChild);
}

int Height(TreeNode* root)
{
    if(root == nullptr)
        return -1;
    else
    return root->height;
}

TreeNode * LLRotation(TreeNode* root)
{
    TreeNode *left = root->leftChild;
    TreeNode *rightOfLeft = left->rightChild;
    //left of root becomes root, and root becomes right child of new root.
    left->rightChild = root;
    //rightofleft becomes left child of old root.
    root->leftChild = rightOfLeft;

    root->height = max(Height(root->leftChild), Height(root->rightChild)) + 1;
    left->height = max(Height(left->leftChild), Height(left->rightChild)) + 1;
    printf("root of balanced subtree: %d\n", left->data);
    return left;
}

TreeNode * LRRotation(TreeNode* root)
{
    TreeNode *left = root->leftChild;
    TreeNode *rightOfLeft = left->rightChild;

    left->rightChild = rightOfLeft -> leftChild;
    root->leftChild = rightOfLeft -> rightChild;
    rightOfLeft->leftChild = left;
    rightOfLeft->rightChild = root;
    
    root->height = max(Height(root->leftChild), Height(root->rightChild)) + 1;
    left->height = max(Height(left->leftChild), Height(left->rightChild)) + 1;
    rightOfLeft->height = max(Height(rightOfLeft->leftChild), Height(rightOfLeft->rightChild)) + 1;
    printf("root of balanced subtree: %d\n", rightOfLeft->data);

    return rightOfLeft;
}

TreeNode * RRRotation(TreeNode* root)
{
    TreeNode *right = root->rightChild;
    TreeNode *leftOfRight = right->leftChild;
    //right of root becomes root, and root becomes left child of new root.
    right->leftChild = root;
    //leftOfRight becomes right child of old root.
    root->rightChild = leftOfRight;

    root->height = max(Height(root->leftChild), Height(root->rightChild)) + 1;
    right->height = max(Height(right->leftChild), Height(right->rightChild)) + 1;
    printf("root of balanced subtree: %d\n", right->data);
    return right;
}

TreeNode * RLRotation(TreeNode* root)
{
    TreeNode *right = root->rightChild;
    TreeNode *leftOfRight = right->leftChild;

    right->leftChild =  leftOfRight -> rightChild;
    root->rightChild = leftOfRight -> leftChild;
    
    leftOfRight->leftChild = root;
    leftOfRight->rightChild = right;
    
    root->height = max(Height(root->leftChild), Height(root->rightChild)) + 1;
    right->height = max(Height(right->leftChild), Height(right->rightChild)) + 1;
    leftOfRight->height = max(Height(leftOfRight->leftChild), Height(leftOfRight->rightChild)) + 1;
    printf("root of balanced subtree: %d\n", leftOfRight->data);
    return leftOfRight;
}
//Insertion Time Complexity for inserting 1 node = O(log n) as we need to search a position of node in BST.
TreeNode* Insert(TreeNode *root, int key){
    if(root == nullptr)
    {
        //Key not present in tree, create new node with key.
        root = new TreeNode(key);
        return root;
    }
    if(key < root->data)
    {
        root->leftChild = Insert(root->leftChild, key);
        root->height = root->leftChild->height + 1;
    }
    else if (key > root->data)
    {
        root->rightChild = Insert(root->rightChild, key);
        root->height = root->rightChild->height + 1;
    }
    int balanceFactor = BalanceFactor(root);
    printf("balance factor for node %d is %d\n", root->data, balanceFactor);
    if(balanceFactor == 2)
    {
        printf("balance factor for left of node %d is %d\n", root->data, BalanceFactor(root->leftChild));

        if(BalanceFactor(root->leftChild) == 1)
        {
            //Node root is LL imbalanced.
            return LLRotation(root);
        }
        else if(BalanceFactor(root->leftChild) == -1)
        {
            //Node root is LR imbalanced.
            return LRRotation(root);
        }
    }
    else if(balanceFactor == -2)
    {
        if(BalanceFactor(root->rightChild) == -1)
        {
            //Node root is RR imbalanced.
            return RRRotation(root);
        }
        else if(BalanceFactor(root->rightChild) == 1)
        {
            //Node root is RL imbalanced.
            return RLRotation(root);
        }
    }
    return root;
}


int main()
{
    TreeNode *root = nullptr;
    int input[] = {50, 40, 45, 50, 90, 75, 25, 60, 30, 70};
    //int input[] = {50, 40, 25};
    //int input[] = {20, 40, 60};
    int len = sizeof(input)/sizeof(input[0]);
    //root = new TreeNode(input[0]);
    for(int i=0; i<len; i++)
    {
        printf("Inserting node %d\n", input[i]);
        root = Insert(root, input[i]);
        printf("new root=%d\n", root->data);
    }
    Inorder(root);
    return 0;
}