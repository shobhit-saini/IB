/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

Seen this question in a real interview before
*/
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int i = 0, j = A.size()-1, k, l, sum = 0, tar, flag = 0, m;
    vector<vector<int>>res;
    vector<int> v(4);
    sort(A.begin(), A.end());
    for(i = 0; i < A.size()-3; i++)
    {
        for(j = i+1; j < A.size()-2; j++)
        {
            k = j+1; l = A.size()-1;
             v[0] = A[i];
             v[1] = A[j];
            tar =B - A[i] - A[j];
            while(k < l)
            {
                sum = A[k] + A[l];
                if(sum == tar)
                {
                    v[2] = A[k];
                    v[3] = A[l];
                    for(m = 0; m < res.size(); m++)
                    {
                        if(res[m] == v)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        res.push_back(v);
                    }
                    flag = 0;
                    k++;
                    l--;
                }
                else if(sum < tar)
                    k++;
                else
                    l--;
            }
        }
    }
    /*while(abs(i - j) >= 2)
    {
        k = i+1;l = j-1;
        v[0] = A[i];
        v[3] = A[j];
        tar =B - (A[i] + A[j]);
        while(k < l)
        {
            sum = A[k] + A[l];
            if(sum == tar)
            {
                v[1] = A[k];
                v[2] = A[l];
                res.push_back(v);
                k++;
                l--;
            }
            if(sum < tar)
                k++;
            else
                l--;
        }
        if(flag == 0)
        {
            i++;
            flag = 1;
        }
        else
        {
            j--;
            flag = 0;
        }
    }*/
    return res;
}
