int Solution::numSetBits(unsigned int A) {
    
    int i = 0, count = 0;
    while(A > 0)
    {
        if(A%2 == 1)
        {
            count++;
        }
        A= A/2;
    }
    return count;
}
