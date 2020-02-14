/*
Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3
Seen this question in a real interview before
*/
int Solution::sqrt(int A) {
    if(A == 0 || A == 1)
    {
        return A;
    }
    int low = 0, high = A-1, sqr, i;
    long int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(mid*mid == A)
        {
            sqr = mid;
            return sqr;
        }
        else if(mid*mid > A)
        {
            high = mid-1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
