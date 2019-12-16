/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1
*/
int Solution::trailingZeroes(int A) {
    int res, no = 0;
    res = A/5;
    no += res; 
    while(res > 0)
    {
        res= res/5;
        no += res;
    }
    return no;
}
