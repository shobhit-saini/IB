vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int, int>mp;
    int i, j = 0, count = 0, k = 0;
    vector<int>v;
    if(B > A.size())
        return v;
    for(j = 0; j < B; j ++)
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
    v.push_back(mp.size());
    count = 0;
    if(mp[A[k]] > 1)
        mp[A[k]] -= 1;
    else
        mp.erase(A[i]);
    k = 1;
    for(i = B; i < A.size(); i++)
    {
            if(mp.find(A[i]) == mp.end())
            {
                mp[A[i]] = 1;
            }
            else
            {
                mp[A[i]] += 1;
            }
            v.push_back(mp.size());
            count = 0;
            if(mp[A[k]] > 1)
                mp[A[k]] -= 1;
            else
                mp.erase(A[k]);
            k++;
            
    }
    return v;
}
