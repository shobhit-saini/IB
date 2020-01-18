int Solution::isPower(int A) {
    int i, n, flag = 0;
    if(A == 1)
    {
        return 1;
    }
    for(i = 2; i <= sqrt(A); i++)
    {
        n = A;
        flag = 0;
        while(n != 1)
        {
            
            if(n % i == 0)
            {
                n /= i;
            }
            else
            {
                flag = 1;
                break;
            }
        }
            if(flag == 0)
            {
                return 1;
            }
    }
        return 0;
}
