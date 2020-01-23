vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i = 0, j = 0;
    vector<int> result;
    while(i != A.size() && j != B.size())
    {
        if(A[i] == B[j])
        {
            i++;
            j++;
            result.push_back(A[i - 1]);
        }
        else if(A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return result;
}
