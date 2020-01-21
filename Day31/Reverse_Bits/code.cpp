unsigned int Solution::reverse(unsigned int A) {
    int i, val = 0, j;
    string res = "";
    for(i = 0; i <= 31; i++)
    {
        res += to_string(A % 2);
        A = A/2;
    }

    for(i = 31, j = 0; i >=0 ; i--, j++)
    {
        val += (res[j] - 48)*pow(2,i);
    }
return val;
}
