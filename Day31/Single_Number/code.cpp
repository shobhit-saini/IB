int Solution::singleNumber(const vector<int> &A) {
    int i = 0, res; 
    for(i = 0; i < A.size(); i++)
    {
        res = res ^ A[i];
    }
return res;
}
