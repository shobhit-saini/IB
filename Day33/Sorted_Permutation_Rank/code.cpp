int fact(int a)
{
    if(a == 1 || a == 0)
    {
        return 1;
    }
    else
    {
        return a*fact(a-1) % 1000003;
    }
}
int Solution::findRank(string A) {
    string str = A;
    int i, res = 0, j, index;
    sort(str.begin(), str.end());
    for(i = 0; i < A.size(); i++)
    {
        for(j = 0; j < A.size(); j++)
        {
            if(str[j] == A[i])
            {
                index = j;
                break;
            }
        }
        str.erase(str.begin() + index);
        res+= index*fact(A.size()-i-1);
    }
    return (res+1)%1000003;
}
