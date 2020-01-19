string Solution::solve(string A) {
    int i = 0, j = A.size()-1;
    string temp = "", res = "";
    vector<string> str;
    while(A[i] == ' ')
    {
        i++;
    }
    while(A[j] == ' ')
    {
        j--;
    }
    for(;i <= j; i++)
    {
        if(A[i] == ' ')
        {
            str.push_back(temp);
            temp = "";
        }
        else
            temp += A[i]; 
    }
    str.push_back(temp);
    for(i = 0, j = str.size()-1; i <= j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    for(i = 0; i < str.size(); i++)
    {
        res += str[i];
        if(i != str.size()-1)
            res += ' ';
    }
    return res;
}
