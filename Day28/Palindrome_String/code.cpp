int Solution::isPalindrome(string A) {
    string str, str1;
    int i, a;
    for(i = 0; i < A.size(); i++)
    {
        a = A[i];
        if((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122) || (A[i]>= 48 && A[i] <= 57))
            str += tolower(A[i]);
    }
    str1 = str;
    reverse(str1.begin(), str1.end());
    if(str1.compare(str) == 0)
    {
        return 1;
    }
    return 0;
}
