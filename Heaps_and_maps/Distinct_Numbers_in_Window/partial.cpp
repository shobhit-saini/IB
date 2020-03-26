/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

 If K > N, return empty array.
 A[i] is a signed integer
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
Seen this question in a real interview before
*/
vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int, int>mp;
    map<int, int>::iterator itr;
    int i, j = 0, count = 0;
    vector<int>v;
    if(B > A.size())
        return v;
    for(i = 0; i <= A.size()-B; i++)
    {
        for(j = i; j < i + B; j ++)
        {
            if(mp.find(A[j]) == mp.end())
            {
                mp[A[j]] = 1;
            }
            else
            {
                mp[A[j]] += 1;
            }
        }
            for(itr = mp.begin(); itr != mp.end(); itr++)
            {
                count++;
            }
            v.push_back(count);
            count = 0;
            mp.clear();
    }
    return v;
}
