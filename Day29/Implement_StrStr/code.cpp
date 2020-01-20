int Solution::strStr(const string A, const string B) {
    int i, j, flag = 0, temp;
    for(i = 0; i < A.size(); i++)
    {
        temp = i;
        for(j = 0; j < B.size() && temp < A.size(); j++)
        {
            if(A[temp++] != B[j])
            {
                break;
            }
        }
        if(j == B.size())
        {
            return i;
        }
    }
    return -1;
}
