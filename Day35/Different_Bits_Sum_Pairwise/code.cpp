const int mod = 1e9 + 7;
int Solution::cntBits(vector<int> &A) {
int i = 0, ans = 0, j,count = 0;
    for(i = 0; i < 32; i++)
    {
        for(j = 0; j < A.size(); j++)
        {
            if(A[j] & 1<<i)
            {
                count++;
            }
        }
        ans += (count* ((long long)A.size()-count) *2)%mod;
        ans = ans%mod;
        count = 0;
    }
    return ans % mod;
}
