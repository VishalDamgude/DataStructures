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

//Similar to insertion sort but elemets that are 'gap' distance apart are inserted into sorted positons in each pass until gap is 1.
void ShellSort(vector<int> &v)
{
    int n = v.size();
    int gap = n/2;
    for(; gap>=1; gap=gap/2)
    {
        int i = gap;
        while(i<n)
        {
            int current = v[i];
            
            int j = i-gap;
            while(j>=0 && v[j] >= current)
            {
                v[j+gap] = v[j];
                j = j-gap;
            }
            v[j+gap] = current;
            i++;
        }
    }
}

int main()
{
    //vector<int> v {8,3,1,7,23,9,5,76,17};
    vector<int> v {8,2,9,6,5,3,7,3,1};
    ShellSort(v);
    Display(v);
    return 0;
}