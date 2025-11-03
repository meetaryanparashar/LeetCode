/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

#include <iostream>

using namespace std;

// first approach
int reverse(int x)
{   int factor = 1;
    if (x == INT32_MIN){return 0;}
    if (x < 0){
        factor = -1;
        x = -x;
    }
    // get length
    int length = 0;
    int num = x;
    while (num != 0)
    {
        num /= 10;
        length++;
    }
    // cout << "length is : " << length<<endl;

    int ans = 0;
    int pow = 1;
    for (int i = 1; i < length; i++)
    {
        pow *= 10;
    }
    while (x != 0)
    {
        if (x % 10 > 2 && pow > 100000000)
        {
            // cout << "Bit overflow "<< endl;
            return 0;
        }
        int to_add = (x % 10) * pow;

        if (to_add > INT32_MAX - ans)
        {
            return 0;
        }
        
        ans += to_add;
        cout << ans<<endl;
        
        x /= 10;
        pow /= 10;
    }
    return ans*factor;
}

int main()
{
    cout << "running!" << INT32_MAX << endl;
    // cout << reverse(1534236469);
    cout << reverse(54622);
    return 0;
}