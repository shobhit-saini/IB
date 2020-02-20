/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Input Format

The only argument given is integer array A.
Output Format

Return the total water it is able to trap after raining..
For Example

Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1: <img src="http://i.imgur.com/0qkUFco.png">
    
    In this case, 6 units of rain water (blue section) are being trapped.
*/
int Solution::trap(const vector<int> &A) {
    int left[A.size()], right[A.size()], max, water = 0, i, min;
    max = A[0];
    for(i = 0; i < A.size(); i++)
    {
        if(max < A[i])
        {
            max = A[i];
        }
        left[i] = max;
    }
    max = A[A.size()-1];
    for(i = A.size()-1; i >= 0; i--)
    {
        if(max < A[i])
        {
            max = A[i];
        }
        right[i] = max;
    }
    for(i = 0; i < A.size(); i++)
    {
        min = (left[i] < right[i])? left[i]:right[i];
        water = water + min-A[i];
    }
    return water;
}
