/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
*/
vector<int> Solution::lszero(vector<int> &A) {
    int limit = -1, i, j, k, flag = 0, sum, flag1 = 0;
    vector<int>v;
    vector<vector<int>>res;
    for(i = 0; i < A.size(); i++)
    {
        sum = A[i];
        if(sum == 0)
        {
            v.push_back(A[i]);
            flag = 1;
        }
        for(j = i+1; j < A.size(); j++)
        {
            sum += A[j];
            if(sum == 0)
            {
                flag1 = 1;
                limit = j;
            }
        }
        if(flag1 == 1)
        {
            if(flag == 0)
            {
                v.push_back(A[i]);
            }
            for(k = i+1; k <= limit; k++)
            {
                v.push_back(A[k]);
            }
        }
        res.push_back(v);
        limit = -1;
        flag = 0;
        flag1 = 0;
        v.clear();
    }
    int max = res[0].size();
    int index = 0;
    for(i = 0; i < res.size(); i++)
    {
        if(res[i].size() > max)
        {
            max = res[i].size();
            index = i;
        }
    }
    return res[index];
}
