/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <iostream>
#include <vector>
using namespace std;


// My first approach.O(n) --> accepted.
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int ptr = n-2;
    int maxProfit = 0;
    int currHighest = n-1;    
    while (ptr >= 0)
    {        
        int profit = prices[currHighest] - prices[ptr];
        if (profit > maxProfit){
            maxProfit = profit;
        }
        if (prices[ptr]> prices[currHighest])
        {
            currHighest = ptr;
        }
        
        ptr--;
    }
    return maxProfit;
}

int main(){
    // vector<int> input = {7,1,5,3,6,4};
    vector<int> input = {7,6,4,3,1};
    cout << maxProfit(input);
    return 0;
}