#include<iostream>
#include<vector>

using namespace std;

void BubbleSort(vector<int> &v)
{
    int n = v.size();
    for(int pass=0; pass<n-1; pass++)
    {
        bool swapsNeeded;
        for(int index=0; index < n-1-pass; index++)
        {
            if(v[index] > v[index+1])
            {
                swap(v[index], v[index+1]);
                swapsNeeded = true;
            }
        }
        if(!swapsNeeded)  //List is sorted as no swaps are performed in above pass.
            break;
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
    BubbleSort(v);
    Display(v);
    return 0;
}