int Solution::removeDuplicates(vector<int> &A) {
    int i =2, count = 0, j = 2;
    if(A.size() == 0 || A.size() == 1)
    {
        return A.size();
    }
    for(j = 2; j < A.size(); j++)
    {
        if(A[i-2] != A[j])
        {
            A[i] = A[j];
            i++;
        }
    }
    return i;
}
