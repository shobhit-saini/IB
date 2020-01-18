int gcd(int A, int B)
{
    if(B == 0)
    {
        return A;
    }
    else
    {
        return gcd(B, A%B);
    }
}

int Solution::cpFact(int A, int B) {
    int i = 1, x;
    while(A > 0)
    {
        if(A%i == 0)
        {
            x = A/i;
            if(gcd(x, B) == 1)
                return x;
        }
        i++;
    }
}
