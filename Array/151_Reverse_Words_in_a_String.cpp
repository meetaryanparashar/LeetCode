/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

#include <iostream>
using namespace std;

string reverseWords(string s) {
        string out = "";
        int len = 0;
        for (int i = s.length()-1; i >=0; i--){
            if (s[i] == ' ')
            {
                if (len > 0){
                    out.append(s.substr(i+1, len) + " ");
                    len = 0;                    
                }              
            }
            else{
                len++;
            }           
        }
        if (s[0] != ' ' && len > 0)
        {
            out.append(s.substr(0, len));
        }
        else{
            out.pop_back();
        }        
        return out;
    }

int main(){
    string input = "The sky is blur";
    cout << "\'";
    cout << reverseWords(input);
    cout << "\'";
    return 0;
}