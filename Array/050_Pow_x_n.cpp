/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

// My brute force approach. - Time limit exceeded.
double myPowBF(double x, int n)
{
    double ans = 1;
    while (n > 0)
    {
        ans = ans * x;
        n--;
    }
    while (n < 0)
    {
        ans = ans / x;
        n++;
    }
    return ans;
}

// My Second approach. ----------- After Spending Hours I finally got this accepted by my own.
double myPowSapp(double x, int n)
{
    double ans = 1;
    int raise = 1;
    double raise_pow = x;
    bool Invert = false;
    bool minCase = false;
    if (n < 0)
    {
        if (n == INT32_MIN)             // we can use long integers to avoid int overflow.
        {
            // cout << "yare yare daza"<<endl;
            n = INT32_MIN + 1;
            cout << n<<endl;
            minCase = true;
        }

        n = n * -1;
        Invert = true;
    }

    while (n > 0)
    {
        if (raise <= n / 2 && raise <= INT32_MAX / 2)
        {
            // cout<< "Raise = "<<raise<<" Raise Power = "<<raise_pow<<endl;
            raise_pow = raise_pow * raise_pow;
            raise = raise * 2;
        }
        else
        {
            // cout << "raise "<<raise << " is greater than n = "<<n<<endl;
            ans = ans * raise_pow;
            n = n - raise;
            raise = 1;
            raise_pow = x;
        }
    }

    if (Invert)
    {
        if (minCase)
        {
            ans = ans * x;
        }
        return (1 / ans);
    }
    else
    {
        return ans;
    }
}


// Binary Exponentiation
double myPow(double x, int n)
{
    long binaryForm = n;
    if (n < 0)
    {
        x = 1/x;
        binaryForm = -binaryForm;
    }
    
    double expo = x;
    double ans = 1;
    while (binaryForm > 0)
    {
        if (binaryForm%2 == 1){
            ans *= expo;
        } 
        expo *= expo;
        binaryForm /= 2;
    }
    return ans;
}

int main()
{
    // cout << myPow(1, 2147483647);
    // cout << myPow(2, -2147483648);
    // cout << myPow(2, -3);
    cout << myPow(0, 0);
    // cout << myPow(2.0, 10);
    // cout << INT32_MIN;
    return 0;
}