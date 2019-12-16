/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*/
vector<int> Solution::subUnsort(vector<int> &A) {
    int i, e, s, j;
    vector<int>result; 
    for(i = 0; i < A.size()-1; i++)
    {
        if(A[i+1] < A[i])
        {
            break;
        }
    }
    s = i;
    for(i = A.size()-1; i > 0; i--)
    {
        if(A[i-1] > A[i])
        {
            break;
        }
    }
    e = i;
    if(s == A.size()-1)
    {
        result.push_back(-1);
        return result;
    }
    int max = INT_MIN, min = INT_MAX;
    for(i = s; i <= e; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
        if(A[i] < min)
        {
            min = A[i];
        }
    }
    for(i = 0; i < s; i++)
    {
        if(A[i] > min)
        {
            s = i;
            break;
        }
    }
    for(i = A.size()-1; i > e; i--)
    {
        if(A[i] < max)
        {
            e = i;
            break;
        }
    }
    result.push_back(s);
    result.push_back(e);
    return result;
}
