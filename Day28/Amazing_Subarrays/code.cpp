int Solution::solve(string A) {
    int i, count = 0;
    for(i = 0; i < A.size(); i++)
    {
        if(A[i] == 'a' ||A[i] == 'e' ||A[i] == 'i' ||A[i] == 'o' ||A[i] == 'u'||A[i] == 'A' ||A[i] == 'E' ||A[i] == 'I' ||A[i] == 'O' ||A[i] == 'U')
        {
            count += A.size() - i;
        }
    }
    return count%10003;
}
