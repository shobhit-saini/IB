int Solution::divide(int A, int B) {
    int i, count = 0, flag = 0, flag1 = 0;
    long int num = A, den = B;

    if(num < 0 && den < 0)
    {
        flag = 1;
        num = -num;
        den = -den;
        
    }

    else if(A < 0 && B >=0)
    {
        flag1 = 1;
        num = -num;
    }
    else if(A >= 0 && B < 0)
    {
        flag1 = 1;
        den = -den;
    }
    if(INT_MIN == A && den == 1)
    {
        if(flag1 == 1)
        {
            return A;
        }
        else
        {
            return INT_MAX;
        }
    }
    while(num >= den)
    {
        count++;
        num = num-den;
    }
    if(flag1 == 1)
    {
        return -count;
    }
    else
    {
        return count;
    }
}
