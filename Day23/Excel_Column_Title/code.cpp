string Solution::convertToTitle(int A) {
    int i = 0, B = A, len = 0, rem;
    string str;
    while(B > 0)
    {
        rem = B%26;
        if(rem == 0)
        {
            str += 'Z';
            B = (B/26) - 1;
        }
        else
        {
            str += (char)(rem + 64);
            B /= 26;
        }
    }
    reverse(str.begin(), str.end());
    return str;
}
