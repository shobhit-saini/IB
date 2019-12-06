/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
*/
int Solution::maximumGap(const vector<int> &A) {
    int i, j, max_dis = -1, dis;
    int Lmin[A.size()], Rmax[A.size()];
    Lmin[0] = A[0]; Rmax[A.size() -1] = A[A.size() -1];
    for(i = 1; i < A.size(); i++)
    {
        Lmin[i] = min(A[i], Lmin[i-1]);
    }
    for(i = A.size()-2; i >=0; i--)
    {
        Rmax[i] = max(A[i], Rmax[i+1]);
    }
    i = 0; j = 0; 
    while(i < A.size() && j < A.size())
    {
        if(Lmin[i] <= Rmax[j])
        {
            if(max_dis < j-i)
            {
                max_dis = j-i;
            }
            j++;
        }
        else
            i++;
    }
    return max_dis;
}
