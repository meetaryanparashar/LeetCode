/*
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

#include <iostream>
using namespace std;


// first approach -> accepted O(n)
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    int size = 0;
    int s = x;

    
    int divisor = 1; // use long to prevent bit overflow
    
    while (s > 0)
    {
        s /= 10;
        size++;
        divisor *= 10;
    }
    divisor /= 10;

    for (int i = 1; i <= size / 2; i++)
    {   
        if (x%10 == (x/divisor)%10)
        {            
            x /= 10;
        }
        else{        
            return false;}
            divisor /= 100;
        }
    return true;
}

int main()
{
    cout << isPalindrome(7513157);
    return 0;
}