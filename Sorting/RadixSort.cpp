#include<iostream>
#include<vector>
#include<math.h>

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

void Insert(Node **buckets, int index, int data)
{
    Node * p = new Node(data);

    if(buckets[index] == nullptr)
        buckets[index] = p;
    else{
        Node * current =  buckets[index];
        while(current->next != nullptr)
            current = current->next;
        current->next = p;
    }
}
//Delete in FIFO order.
int Delete(Node ** buckets, int index)
{
    Node *current = buckets[index];
    int data = current->val;
    buckets[index] = current->next;

    delete current;
    return data;
}

int getDigits(int n)
{
    if(n==0) return 1;
    int noOfDigits = 0;
    while(n!=0)
    {
        n=n/10;
        noOfDigits++;
    }
    return noOfDigits;
}
void RadixSort(vector<int> &v)
{
    int max = getMax(v);
    int max_digits= getDigits(max);
    int n = v.size();
    int bucketSize = 10;

    //Create buckets array of size 10 i.e 0 to 9 for base 10 radix sort.
    Node** buckets = new Node*[bucketSize];

    for(int i=0; i<bucketSize; i++)
    {
        buckets[i] = nullptr;
    }
    int radix =0;
    while(radix < max_digits)
    {
        for(int i=0; i<n; i++)
        {
            int pos = (int)(v[i]/pow(10,radix)) % 10;
            Insert(buckets, pos, v[i]);
        }

        int i=0, j=0;
        while(i < bucketSize)
        {
            while(buckets[i] != nullptr)
            {
                //Return element from linked list at index i and delete it from bucket i.
                v[j++] = Delete(buckets, i);
            }
            i++;
        }
        radix++;

    }
    
    delete [] buckets;
}

int main()
{
    vector<int> v {878,453,51,277,123,99,455,876,217};
    //vector<int> v {8,7,6,5,4,3};
    RadixSort(v);
    Display(v);
    return 0;
}