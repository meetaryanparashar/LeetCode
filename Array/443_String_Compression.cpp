/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.
*/

#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char>& chars) {
        string s = "";
        // s + 'a';
        s+chars[0];
        int count = 1;
        for (int i = 1; i < chars.size(); i++){
            if (chars[i] == chars[i-1])
            {
                count++;
            }
            else{ // adding count in string.
                string num = "";
                int digit;
                int digit_count = 0;
                while (count > 0)
                {
                    digit = count%10;
                    count = count/10;
                    digit_count++;
                    num = num+char(digit+48);
                }
                for (int i = digit_count -1; i >=0; i++)
                {
                    s.append(num[i]);
                    s = s+num[i];
                }
                count = 1;
                s = s+chars[i];
            }
            
        }
        for (char x : chars){
            cout << s << " ";
        }
        return 0;
    }

int main(){
    vector<char> input = {'a', 'a','b', 'c', 'c', 'c','c'};
    compress(input);
    return 0;
}