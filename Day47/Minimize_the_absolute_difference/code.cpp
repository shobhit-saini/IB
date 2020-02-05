int max(int i, int j)
{
    return i > j ? i:j;
}
int min(int i, int j)
{
    return i < j ? i:j;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = A.size()-1, j = B.size()-1, k = C.size()-1, maxx, curr_diff;
    int min_difference = abs(max(A[i],max(B[j],C[k])) - min(A[i], min(B[j],C[k])));
    while(i != -1 && j != -1 && k != -1)
    {
        curr_diff = abs(max(A[i],max(B[j],C[k])) - min(A[i], min(B[j],C[k])));
        if(curr_diff < min_difference)
            min_difference = curr_diff;
        maxx = max(A[i],max(B[j],C[k]));
        if(A[i] == maxx)
            i -= 1;
        else if(B[j] == maxx)
            j -= 1;
        else
            k -= 1;
    }
    return min_difference;
}
