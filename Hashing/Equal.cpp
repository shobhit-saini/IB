/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.

Seen this question in a real interview before
*/
vector<int> Solution::equal(vector<int> &A) {
    map<int, pair<int, int>>mp;
    vector<pair<pair<int, int>, pair<int, int>>>pp;
    vector<int> v;
    int i, j, sum;
    for(i = 0; i < A.size(); i++)
    {
        for(j = i+1; j < A.size(); j++)
        {
            sum = A[i] + A[j];
            pair<int, int>p = {i, j};
            pair<int, int>t;
            if(mp.find(sum) != mp.end())
            {
                t = mp[sum];
                if(t.first < t.second && p.first < p.second && t.first < p.first && t.second != p.second && t.second != p.first)
                {
                    pp.push_back({t, p});
                }
            }
            else
            {
                mp[sum] = p;
            }
        }
    }
    sort(pp.begin(), pp.end());
    v.push_back(pp[0].first.first);
    v.push_back(pp[0].first.second);
    v.push_back(pp[0].second.first);
    v.push_back(pp[0].second.second);
    return v;
}
