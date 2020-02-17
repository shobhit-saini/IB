/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
*/

int Solution::pow(int x, int n, int d) {
    long long int result = 1;
    long long int b = x;
    while(n > 0)
    {
        if(n&1)
        {
            result = ((result%d)*(b))%d;
        }
        b = ((b)*(b))%d;
        n >>=1;
    }
    
    if(result < 0)
    {
        result = (result+d)%d;
        return result;
    }
    else
        return result%d;
}
