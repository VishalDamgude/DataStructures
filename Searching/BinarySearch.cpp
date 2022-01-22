#include <iostream>
#include<vector>
using namespace std;

int findPeakElementInMountainArray(vector<int>& nums)
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

//Binary Search in a rotated sorted array.Return index of target element, return -1 if not found.
//e.g. A= {5,6,7,8,9,1,2,3}
int RotatedBinarySearch(vector<int> &nums, int target, int start, int end)
{
    if(start > end)
        return -1;
    int mid = start + (end-start)/2;
    if(nums[mid] == target)
        return mid;

    //Check if first half upto mid is sorted 
    if(nums[start] <= nums[mid])
    {
        //first half is sorted, check if target lies in this half
        if(target >= nums[start] && target <= nums[mid])
        {
            return RotatedBinarySearch(nums, target, start, mid-1);
        }
        //else search in second half.
        return RotatedBinarySearch(nums, target, mid+1, end);
    }
    //First half is not sorted, then second half must be sorted.
    //Check if target lies in second half.
    if(target >= nums[mid] && target <= nums[end])
    {
        return RotatedBinarySearch(nums, target, mid+1, end);
    }
    //else search in first half.
    return RotatedBinarySearch(nums, target, start, mid-1);
}
int main(){

    vector<int> nums {2,4,5,6,7,8,9,10};
    binarySearch(nums, 9, 0,nums.size()-1);
    vector<int> rotatedArray = {5,6,7,8,9,1,2,3};
    cout << RotatedBinarySearch(rotatedArray, 2, 0, rotatedArray.size() -1) << endl;

    return 0;
}