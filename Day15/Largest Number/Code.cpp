int Compare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string>B;
    string str, result;
    char ch = 0;
    int i, flag = 0;
    for(i = 0; i < A.size(); i++)
    {
        str = to_string(A[i]);
        B.push_back(str);
    }
    sort(B.begin(), B.end(), Compare);
    for(i = 0; i < B.size()-1; i++)
    {
        if(B[i] == "0" && flag == 0)
        {
        }
        else
        {
            result.append(B[i]);
            flag = 1;
        }
    }
    result.append(B[i]);
    return result;
}
