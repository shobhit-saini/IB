string Solution::addBinary(string A, string B) {
    int i, j, var, c = 0;
    vector<string> str;
    string res = "";
    for(i = B.size()-1, j = A.size()-1; i >= 0 && j >=0; i--, j--)
    {
        var = (A[j]-48) + (B[i]-48) + c;
        if(var == 0)
        {
            c = 0;
            res+= '0';
        }
        else if(var == 1)
        {
            c = 0;
            res+= '1';
        }
        else if(var == 2)
        {
            c = 1;
            res+= '0';
        }
        else if(var == 3)
        {
            c = 1;
            res+= '1';
        }
    }
    while(i>=0)
    {
        var = (B[i]-48) + c;
         if(var == 0)
        {
            c = 0;
            res+= '0';
        }
        else if(var == 1)
        {
            c = 0;
            res+= '1';
        }
        else if(var == 2)
        {
            c = 1;
            res+= '0';
        }
        i--;
    }
    while(j>=0)
    {
        var = (A[j]-48) + c;
        if(var == 0)
        {
            c = 0;
            res+= '0';
        }
        else if(var == 1)
        {
            c = 0;
            res+= '1';
        }
        else if(var == 2)
        {
            c = 1;
            res+= '0';
        }
        j--;
    }
    if(c == 1)
    {
        res+= to_string(c);;
    }
    reverse(res.begin(), res.end());
    return res;
}
