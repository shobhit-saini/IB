int Solution::isPalindrome(int A) {
    int temp = A, count = 0;
    if(A < 0)
    {
        return 0;
    }
    if(A /10 <= 0)
    {
        return 1;
    }
    while(temp != 0)
    {
        temp = temp/10;
        count++;
    }
    int i = count-1;
    int j = 1;
    temp = A;
    while(i >= j)
    {
        
        int var = pow(10,1);
        int left = (A/pow(10,i));
        left = left%10;
        int right = temp%var;
        if(left != right)
            return 0;
        i--; j++;temp = temp/10;
    }
    return 1;
    
}
