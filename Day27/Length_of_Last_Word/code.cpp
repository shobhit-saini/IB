int Solution::lengthOfLastWord(const string A) {
    int i = A.size() - 1, len = 0;
    while(A[i] == ' ')
        i--;
    for(; i >=0; i--)
    {
        if(A[i] == ' ')
        {
            break;
        }
        len++;
    }
    return len;
}
