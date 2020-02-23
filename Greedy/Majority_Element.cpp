/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.
*/
int Solution::majorityElement(const vector<int> &A) {
    int i, count = 0, maj;
    for(i = 0; i < A.size(); i++)
    {
        if(count == 0)
        {
            maj = A[i];
            count = 1;
        }
        else if(A[i] == maj)
        {
            count++;
        }
        else
        {
            count--;
        }
        
    }
    return maj;
}
