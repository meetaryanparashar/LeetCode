/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 */

 // Solved Without using obvious string functions.

 #include <iostream>

 using namespace std;

 
 bool checkPart(string subs, string part){
    // cout << "Inside checking "<< endl;
    int size = subs.length();
    for (int i = 0; i < size; i++)
    {
        if (subs[i] != part[i])
        {
            // cout << "Nope "<< endl;
            return false;
        }
    }  
    // cout << "Yoope !" <<endl;
    return true;
 }
 
 string removeOccurrences(string s, string part) {
        int slen, partlen;
        slen = s.length();
        partlen = part.length();

        for (int i = 0; i < slen; i++){
            // cout << "i == "<< i <<endl;
            if (s[i] == part[0])
            {
                // cout << "match !" <<endl;
                if ((slen - i) >= partlen && checkPart(s.substr(i, partlen), part)){
                    slen = slen - partlen;
                    s = s.substr(0, i) + s.substr(i+partlen);
                    // s.resize(slen);
                    // cout << "s now is : "<<s<<endl;
                    // cout <<"resetting i"<<endl;
                    i = -1;
                }
            }//cout << "i is still "<<i<<endl;
        }
        // cout <<"printing s";
        return s;
    }

int main(){
    string input = "axxxxyyyyb";
    string part = "xy";
    cout << removeOccurrences(input, part) << endl;
    // cout << "Done!!";
}
