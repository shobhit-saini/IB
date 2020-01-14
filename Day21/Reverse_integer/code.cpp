int Solution::reverse(int A) {
    int digit = 0, n = A, m = A, i;
    double result = 0;
    if(A < 0)
    {
        n = -n;
        m = -m;
    }
    do
    {
        digit++;
        n = n/10;
    }while(n != 0);
    for(i = digit-1; i >= 0; i--)
    {
        result += pow(10, i)*(m % 10);
        m = m/10;
    }

    if(A < 0)
    {
        result = -result;
    }
    if(result >= 2147483642 || result <= -2147483642)
    {
        return 0;
    }
    return result;
}
