string Solution::longestCommonPrefix(vector<string> &A) {
    int i, flag = 0, j;
    string var, res= "", temp;
    int min_len = A[0].size();
    int index = 0;
    for(i = 1; i < A.size(); i++)
    {
        if(min_len > A[i].size())
        {
            min_len = A[i].size();
        }
    }
    for(i = 0; i < min_len; i++)
    {
        var = A[0][i];
        for(j = 0; j < A.size(); j++)
        {
            temp = A[j][i];
            if(temp.compare(var) != 0)
            {
                flag = 1;
                break;
               
            }
            
        }
        if(flag == 1)
            break;
        res += var;
    }
    return res;
}
