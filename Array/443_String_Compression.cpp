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


// Accepted !!!
int compress(vector<char> &chars)
{
    if (chars.size() ==1)
    {
        return 1;
    }
    

    string s = "";

    s.push_back(chars[0]);
    int freq = 1;

    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] == chars[i - 1])
        {
            // cout << "adding freq i is : " << i << endl;
            freq++;
        }
        else
        {
            if (freq != 1)
            {
                // cout << "freq is : " << freq << endl;
                // convert freq into digit char
                string digits = "";

                while (freq > 0)
                {
                    digits.push_back(char(int('0') + freq % 10));
                    freq = freq / 10;
                }
                while (digits.length() != 0)
                {
                    s.push_back(digits.back());
                    digits.pop_back();
                }
                freq = 1;
            }
            s.push_back(chars[i]);
        }
    }
    // cout << "safe here" << endl;
    if (chars[chars.size()-1] == chars[chars.size() - 2])
    {
        // cout << "freq now is : "<<freq<<endl;
        string digits = "";

        while (freq > 0)
        {
            digits.push_back(char(int('0') + freq % 10));
            freq = freq / 10;
        }
        while (digits.length() != 0)
        {
            s.push_back(digits.back());
            digits.pop_back();
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        chars[i] = s[i];
    }
    

    // for (char x : chars)
    // {
    //     cout << x << " ";
    // }
    return s.length();
}

int main()
{
    vector<char> input = {'a'};
    cout << compress(input);
    return 0;
}