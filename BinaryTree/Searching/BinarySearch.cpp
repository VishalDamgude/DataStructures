#include <iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums)
{
    int start = 0;
    int end = nums.size()-1;
    //We have to search max element in array.
    while(start < end)
    {
        int mid = start + (end-start)/2;
        //compare with mid to find max element
        if(nums[mid] > nums[mid+1])
        {
            //In decreasing part of array. so mid may be max but search on left side.(start to mid)
            end = mid;
        } else {
            //In ascending part of array, so mid may be max but search on right side.(mid+1 to end)
            start = mid + 1; //mid+1 is > mid
        }
    }
    //When start equals end, its the max element.
    return start;  //or end.
}

//Order Agnostic Binary search. Will search for target in given sorted array which can be in ascending/descending order.
int binarySearch(vector<int> & nums, int target, int start, int end)
{
    bool isAscending = nums[start] < nums[end] ? true : false;

    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(target < nums[mid])
        {
            if(isAscending)
                end = mid -1;
            else
                start = mid + 1;

        } else if (target > nums[mid]) 
        {
            if(isAscending)
                start = mid + 1;
            else
                end = mid -1;
        }
        else
        {
            //found target.Return its index.
            return mid;
        }
    }
    return -1;
}
int main(){

    vector<int> nums {2,4,5,6,7,8,9,10};
    binarySearch(nums, 9, 0,nums.size()-1);

    return 0;
}