#include<iostream>
#include<vector>

using namespace std;


void SelectionSort(vector<int> &v)
{
    int n = v.size();
    int i,j,minIndex;

    for(i=0; i<n-1; i++)
    {
        for(j=minIndex=i; j<n; j++)
        {
            if(v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i], v[minIndex]);
    }
}

void Display(vector<int> &v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v {8,3,1,7,23,9,5,76,17};
    SelectionSort(v);
    Display(v);
    return 0;
}