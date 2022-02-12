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

int Partition(vector<int> &v, int start, int end)
{
    int n = v.size();
    int pivot = v[start];   //pivot can be any element...middle or random.
    int i = start;
    int j = end;
    while(i<j)
    {
        while(v[i] <= pivot)
            i++;            //Continue until element greater than pivot is found.
        while(v[j] > pivot)
            j--;            //Continue until element smaller than or equal to pivot is found.
        if(i<j)
            swap(v[i], v[j]);   //swap smaller and greater element at j and i respectively.
    }
    swap(v[start], v[j]);   //swap pivot with element at j to place pivot at its correct sorted position when i equals or exceeds j.
    Display(v);
    return j;
}

int PartitionDescending(vector<int> &v, int start, int end)
{
    int n = v.size();
    int pivot = v[start];   //pivot can be any element...middle or random.
    int i = start;
    int j = end;
    while(i<j)
    {
        while(v[i] >= pivot)
            i++;            //Continue until element smaller than pivot is found.
        while(v[j] < pivot)
            j--;            //Continue until element greater than or equal to pivot is found.
        if(i<j)
            swap(v[i], v[j]);   //swap smaller and greater element at j and i respectively.
    }
    swap(v[start], v[j]);   //swap pivot with element at j to place pivot at its correct sorted position when i equals or exceeds j.
    Display(v);
    return j;
}

void QuickSort(vector<int> &v, int start, int end, bool isAscending)
{
    if(start < end)
    {
        int partitionIndex = -1;
        if(isAscending)
        {
            partitionIndex = Partition(v, start, end);
        }
        else
        {
            partitionIndex = PartitionDescending(v, start, end);
        }
        QuickSort(v, start, partitionIndex -1, isAscending);
        QuickSort(v, partitionIndex + 1, end, isAscending);
    }
}

int main()
{
    //vector<int> v {8,3,1,7,23,9,5,76,17};
    vector<int> v {8,7,6,5,4,3};
    //int partitionIndex = Partition(v, 0, v.size()-1);
    //QuickSort(v, 0, v.size()-1, true);
    QuickSort(v, 0, v.size()-1, false);
    Display(v);
    return 0;
}