#include<iostream>
#include<vector>

using namespace std;

void Display(vector<int> &v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void InsertMaxHeap(vector<int> &v, int index)
{
    int currentElement = v[index];
    int parent = (index-1)/2;
    //cout << "index " << index << " parent " << parent << endl;
    int currentIndex = index;
    while(parent >=0 && v[parent] < v[currentIndex])
    {
        swap(v[parent], v[currentIndex]);
        currentIndex = parent;
        parent = (parent-1)/2;
    }
}
void CreateMaxHeap(vector<int> &v){
    for(int i=1; i<v.size(); i++)
    {
        InsertMaxHeap(v, i);
    }
}

void Heapify(vector<int> &v)
{
    //start heapify from end of list.
    int n = v.size();
    int i = n - 1;
    while(i>=0)
    {
        int parent = i;
        int leftChild = parent*2 + 1;
        while(leftChild < n-1)
        {
            int rightChild = leftChild + 1;
            int maxChildIndex = v[leftChild] > v[rightChild] ? leftChild : rightChild;
            if(v[parent] < v[maxChildIndex])
            {
                swap(v[parent], v[maxChildIndex]);
                parent = maxChildIndex;
                leftChild = 2*parent+1;
            }
            else
                break; //parent is at proper position.
        }
        i--;
    }
}
//Deletes root of max-heap and returns it.
int DeleteMaxHeap(vector<int> &v, int &arraySize)
{
    int data = v[0];
    //put last element at root postion.
    v[0] = v[arraySize-1];
    int parent = 0;
    int leftChildIndex = 1;
    while(leftChildIndex < arraySize-2)
    {
        int maxChildIndex = v[leftChildIndex] > v[leftChildIndex+1] ? leftChildIndex : leftChildIndex + 1;
        if(v[parent] < v[maxChildIndex])
        {
            swap(v[parent], v[maxChildIndex]);
            parent = maxChildIndex;
            leftChildIndex = 2*parent+1;
        }
        else
            break;
    }
    v[arraySize-1] = data;
    arraySize--;
    return data;
}

void HeapSort(vector<int> &v)
{
    CreateMaxHeap(v);
    for(int i=v.size(); i>0;)
    {
        DeleteMaxHeap(v, i);
    }
}

int main()
{
    vector<int> v {8,3,1,7,23,9,5,76,17};
    //vector<int> v {10,35,20,5,40,15,25};
    //vector<int> v {8,2,9,6,5,3,7,3,1};
    //CreateMaxHeap(v);
    //HeapSort(v);
    Heapify(v);
    Display(v);
    return 0;
}