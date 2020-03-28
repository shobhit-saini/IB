vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int sum, i = A.size(), j = B.size();
    vector<int> v;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>>pq;
    sum = A[i-1] + B[j-1];
    pq.push(make_pair(sum, make_pair(i-1, j-1)));
    set<pair<int, int>>s;
    s.insert(make_pair(i-1, j-1));
    for(i = 0; i < A.size(); i++)
    {
        pair<int, pair<int, int>>tmp = pq.top();
        pq.pop();
        v.push_back(tmp.first);
        int i = tmp.second.first;
        int j = tmp.second.second;
        sum = A[i] + B[j-1];
        pair<int, int>tmp1 = {i, j-1};
        if(s.find(tmp1) == s.end())
        {
            pq.push(make_pair(sum, tmp1));
            s.insert(tmp1);
        }
        sum = A[i-1] + B[j];
        tmp1 = {i-1, j};
        if(s.find(tmp1) == s.end())
        {
            pq.push(make_pair(sum, tmp1));
            s.insert(tmp1);
        }
    }
    return v;
}
