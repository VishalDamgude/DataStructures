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

void Merge(vector<int> &v, int start, int mid, int end)
{
    int n = v.size();
    vector<int> res(end-start+1);
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid && j <=end)
    {
        if(v[i] < v[j])
            res[k++] = v[i++];
        else
            res[k++] = v[j++];
    }
    while(i<=mid)
        res[k++] = v[i++];
    
    while(j<=end)
        res[k++] = v[j++];
    
    k=0;
    for(i=start; i<=end; i++)
        v[i] = res[k++];
}

void IterativeMergeSort(vector<int> &v, int n)
{
    int listsize;
    for(listsize = 2; listsize <= n; listsize *= 2)
    {
        for(int i=0; i+listsize-1 < n; i=i+listsize)
        {
            int start = i;
            int end = i+listsize - 1;
            int mid = start + (end - start) / 2;
            Merge(v, start, mid, end);
        }
        Display(v);
    }

    if(listsize/2 < n)
        Merge(v, 0, listsize/2 - 1, n-1);
}
void MergeSort(vector<int> &v, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end-start)/2;
        MergeSort(v, start, mid);
        MergeSort(v, mid+1, end);
        Merge(v, start, mid, end);
    }

}

int main()
{
    vector<int> v {8,3,1,7,23,9,5,76,17};
    //vector<int> v {8,7,6,5,4,3};
    //IterativeMergeSort(v, v.size());
    MergeSort(v, 0, v.size()-1);
    Display(v);
    return 0;
}