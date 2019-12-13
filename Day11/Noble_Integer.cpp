/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.
*/
int Solution::solve(vector<int> &A) {
    int i, j;
    sort(A.begin(), A.end());
    for(i = 0; i < A.size(); i++)
    {
       if(A[i] < 0 )
       {
           continue;
       }
       if(i+1 < A.size() && A[i] == A[i + 1])
       {
           continue;
       }
       j = A[i];
       
       if(A.size()-1 - i == j)
       {
           return 1;
       }
    }
    return -1;
}
