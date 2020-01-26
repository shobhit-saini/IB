int Solution::removeElement(vector<int> &A, int B) {
    int i , j = 0;
    for(i = 0; i < A.size(); i++)
    {
        while(i < A.size() && A[i] == B)
        {
            i++;
        }
        if(A.size() == i)
            break;
        A[j] = A[i];
        j++;
    }
    A.resize(j);
    return j;
}
