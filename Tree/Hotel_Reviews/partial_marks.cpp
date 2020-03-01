vector<int> Solution::solve(string A, vector<string> &B) {
    multimap<int, int, greater<int>>m;
    vector<string> v, v1;
    vector<int> res;
    int i, j, k, count = 0;
    string s ;
    for(i = 0; i < A.size(); i++)
    {
        if(i == A.size()-1)
        {
            s = s + A[i];
            v.push_back(s);
        }
        else if(A[i] == '_')
        {
            v.push_back(s);
            s = "";
        }
        else
        {
            s = s + A[i];
        }
    }
    s = "";
    int flag = 0, l;
    for(i = 0; i < B.size(); i++)
    {
        string str = B[i];
        s = "";
        for(l = 0; l < str.size(); l++)
        {
            if(l == str.size()-1)
            {
                s = s + str[l];
                v1.push_back(s);
            }
            else if(str[l] == '_')
            {
                v1.push_back(s);
                s = "";
            }
            else
            {
                s = s + str[l];
            }
        }
        for(j = 0; j < v1.size(); j++)
        {
            for(k = 0; k < v.size(); k++)
            {
                if(v[k] == v1[j])
                {
                    count++;
                    break;
                }
            }
        }
        v1.clear();
        m.insert(make_pair(count, i));
        count = 0;
    }
    multimap<int, int>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++)
    {
        res.push_back(itr->second);
    }
    return res;
}
