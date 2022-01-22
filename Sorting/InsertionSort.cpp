#include<iostream>
#include<vector>

using namespace std;


//TODO - Insertion sort on linked list
void InsertionSort() {

}


void InsertionSort(vector<int> &v)
{
    int n = v.size();
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        int x = v[i];
        while(j>=0 && v[j] > x)
        {
            v[j+1] = v[j]; //keep shifting one place to right until smaller or equal element is found.
            j--;
        }
        v[j+1] = x;
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
    InsertionSort(v);
    Display(v);
    return 0;
}