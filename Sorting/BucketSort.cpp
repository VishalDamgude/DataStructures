#include<iostream>
#include<vector>

using namespace std;

class Node {
    public:
        int val;
        Node * next;
        Node(int d)
        {
            val = d;
            next = nullptr;
        }
};

void Display(vector<int> &v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int getMax(vector<int> &v)
{
    int max = INT_MIN;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] > max)
            max = v[i];
    }
    return max;
}

void Insert(Node **buckets, int index)
{
    Node * p = new Node(index);

    if(buckets[index] == nullptr)
        buckets[index] = p;
    else{
        Node * current =  buckets[index];
        while(current->next != nullptr)
            current = current->next;
        current->next = p;
    }
}

int Delete(Node ** buckets, int index)
{
    Node *current = buckets[index];
    int data = current->val;
    buckets[index] = current->next;

    delete current;
    return data;
}

//BucketSort: or Bin Sort, will work on any user defined data types.
void BucketSort(vector<int> &v)
{
    int max = getMax(v);
    int n = v.size();
    Node** buckets = new Node*[max+1];

    for(int i=0; i<max+1; i++)
    {
        buckets[i] = nullptr;
    }
    for(int i=0; i<n; i++)
    {
        //Element v[i] will act as index/position in buckets array.
        Insert(buckets, v[i]);
    }

    int i=0, j=0;
    while(i < max+1)
    {
        while(buckets[i] != nullptr)
        {
            //Return element from linked list at index i and delete it from bucket i.
            v[j++] = Delete(buckets, i);
        }
        i++;
    }
    delete [] buckets;
}

int main()
{
    vector<int> v {8,3,1,7,23,9,5,76,17};
    //vector<int> v {8,7,6,5,4,3};
    BucketSort(v);
    Display(v);
    return 0;
}