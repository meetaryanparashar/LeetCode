/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

// first approach
int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size()-2;  // assuming peak is not at start or end of array.

        while(l <= r){
            int mid = l + (r-l)/2;
            if (arr[mid-1] < arr[mid] && arr[mid + 1] < arr[mid]){
                return mid;
            }
            if (arr[mid-1] < arr[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }

int main(){
    vector<int> input = {3,5,3,2,0};
    cout << peakIndexInMountainArray(input);
    return 0;
}