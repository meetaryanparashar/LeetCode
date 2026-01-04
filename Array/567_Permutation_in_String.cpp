/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

#include <iostream>
#include <vector>
using namespace std;


// first attempt solved (after correcting an edge case)
bool checkPerm(vector<int> a, string b){
    for (char x : b){
        if (a[x-97] <= 0)
        {
            return false;
        }
        else{
            a[x-97]--;
        }
        
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()){return false;} // edge case
        vector<int> s1_char(26,0);
        for (char c : s1){
            // cout << c - 97 << " done "; 
            s1_char[c - 97]++;
        }

        for (int i = 0; i <= s2.length() - s1.length(); i++){
            if (checkPerm(s1_char, s2.substr(i, s1.length()))){
                return true;
            }
        }
        return false;
    }

int main(){
    string s1 = "ab";
    string s2 = "zbuaasba";
    cout << checkInclusion(s1, s2) << endl;
}