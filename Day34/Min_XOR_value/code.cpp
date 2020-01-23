int Solution::findMinXor(vector<int> &A) {
    int i, res, min = INT_MAX;
    sort(A.begin(), A.end());
    for(i = 0; i < A.size()-1; i++)
    {
        res = A[i]^A[i+1];
        if(min > res)
        {
            min = res;
        }
    }
    return min;
}
