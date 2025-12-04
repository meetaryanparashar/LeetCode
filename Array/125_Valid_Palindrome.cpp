/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    int left = 0, right = n - 1;
    while (left < right)
    {
        // check if characters are alpha-numeric.

        if ((int(s[left]) >= 48 && int(s[left]) <= 57) || (int(s[left]) >= 65 && int(s[left]) <= 90) || (int(s[left]) >= 97 && int(s[left]) <= 122))
        {
            // now valid numbers or characters

            if (int(s[left]) >= 65 && int(s[left]) <= 90)
            {
                s[left] = char(int(s[left]) + 32);
            } // now lowercase
        }
        else
        {
            left++;
            continue;
        }

        if ((int(s[right]) >= 48 && int(s[right]) <= 57) || (int(s[right]) >= 65 && int(s[right]) <= 90) || (int(s[right]) >= 97 && int(s[right]) <= 122))
        {
            // now valid numbers or characters

            if (int(s[right]) >= 65 && int(s[right]) <= 90)
            {
                s[right] = char(int(s[right]) + 32);
            } // now lowercase
        }
        else
        {
            right--;
            continue;
        }

        // check if they are equal
        if (s[left] == s[right])
        {
            left++;
            right--;
            continue;
        }
        else{return false;}
        
    }
    return true;
}

int main()
{
    string input = "Race2e car!";
    // cout << int(input[4]);
    cout << isPalindrome(input);
    return 0;
}