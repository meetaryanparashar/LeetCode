/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

#include <iostream>
#include <vector>
using namespace std;

// first simple approach -- accepted
void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    vector<int> out(size);
     for (int i = 0; i < size; i++)
     {  int idx = i-k;
        while (idx <0){
            idx  += size;
        }
        out[i] = nums[idx%size];
     }
     
     nums = out;
    }

void rotate_2(vector<int>& nums, int k){
    
}

int main(){
    // cout << (-7)%3;
    vector<int> input = {1,2};
    rotate(input, 7);
    for (int x : input){
    cout << x << " ";}
    return 0;
}