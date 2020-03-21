vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> m;
    vector<vector<int>> res;
    int i, j;
    string s;
    for(i = 0; i < A.size(); i++)
    {
        s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i+1);
    }
    unordered_map<string, vector<int>>::iterator itr = m.begin();
    while(itr != m.end())
    {
        res.push_back(itr -> second);
        itr++;
    }
    return res;
}
