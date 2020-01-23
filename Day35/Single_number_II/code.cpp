int Solution::singleNumber(const vector<int> &A) {
    int i, j, count = 0, result = 0;
    for(i = 0; i < 32; i++)
    {
        for(j = 0; j < A.size(); j++)
        {
            if((A[j] & (1<<i))!=0)
            {
                count++;
            }
        }
        result = result | ((count%3) << i);
        count = 0;
    }
    return result;
}
