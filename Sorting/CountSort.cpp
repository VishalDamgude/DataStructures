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

//will work on non-zero positive integers.
void CountSort(vector<int> &v)
{
    int max = getMax(v);
    int * count = new int[max+1];

    for(int i=0; i<max+1; i++)
    {
        count[i] = 0;
    }
    for(int i=0; i<v.size(); i++)
    {
        count[v[i]]++;
    }

    int i=0, j=0;
    while(i < max+1)
    {
        while(count[i] > 0)
        {
            v[j++] = i;
            count[i]--;
        }
        i++;
    }

}

int main()
{
    vector<int> v {8,3,1,7,23,9,5,76,17};
    //vector<int> v {8,7,6,5,4,3};
    CountSort(v);
    Display(v);
    return 0;
}