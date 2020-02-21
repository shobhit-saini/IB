/*
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Find the area of largest rectangle in the histogram.



Input Format

The only argument given is the integer array A.
Output Format

Return the area of largest rectangle in the histogram.
For Example

Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/
int Solution::largestRectangleArea(vector<int> &A) {
    int i, j, count = 0, min = INT_MAX, max = INT_MIN, area;
    for(i = 0; i < A.size(); i++)
    {
        count = 0;
        min = A[i];
        for(j = i; j < A.size(); j++)
        {
            count++;
            if(A[j] < min)
            {
                min = A[j];
            }
            area = min * count;
            if(area > max)
            {
                max = area;
            }
            
        }
    }
    return max;
}
