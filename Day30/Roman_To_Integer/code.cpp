int Solution::romanToInt(string A) {
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0, i;
    for(i = A.size()-1; i >= 0; i--)
    {
        if((i-1)>=0 && mp[A[i-1]] < mp[A[i]])
        {
            res += -mp[A[i-1]] + mp[A[i]];
            i--;   
        }
        else
        {
            res += mp[A[i]];
        }
    }
    return res;
}
