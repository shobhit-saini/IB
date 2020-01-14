int Solution::titleToNumber(string A) {
    int len = A.size();
    int total = 0;
    int len1 = len-1, int_value, i;
    for(i = 0; i < len; i++)
    {
        int_value = A[i] - 64;
        total += int_value * pow(26, len1);
        len1--;
    }
    return total;
}
