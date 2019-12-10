int Solution::firstMissingPositive(vector<int> &A) {
    int i, j, temp;
    for(i = 0; i < A.size(); i++)
    {
        if(A[i] > 0 && A[i] <= A.size())
       {
           j = A[i] - 1;
           if(A[i] != A[j])
           {
               temp = A[i];
               A[i] = A[j];
               A[j] = temp;
               i--;
           }
       }
    }
    for(i = 0; i < A.size(); i++)
    {
        if(A[i] != i+1)
        {
            return i+1;
        }
    }
    return A.size() + 1;
   
}
