vector<int> Solution::nextPermutation(vector<int> &A) {
    int k = A.size()-2, l, temp;
    while(k >= 0 && A[k] > A[k+1])
    {
        k--;
    }
    if(k == -1)
    {
        reverse(A.begin()+(k + 1), A.end());
        return A;
    }
    for(l = A.size()-1; l > k; l--)
    {
        if(A[k] < A[l])
        {
            temp = A[k];
            A[k] = A[l];
            A[l] = temp;
            break;
        }
    }
    reverse(A.begin()+(k + 1), A.end());
    return A;
}
