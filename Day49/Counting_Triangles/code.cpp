int Solution::nTriang(vector<int> &A) {
    int j, k, result = 0;
    sort(A.begin(), A.end());
    for(int i = A.size()-1; i > 1; i--)
    {
        j = 0; k = i-1;
        while(j < k)
        {
            if(A[j] + A[k] > A[i])
            {
                result = (result + (k-j)%1000000007)%1000000007;
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}
