/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

Seen this question in a real interview before
*/
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int>v;
    map<string, int>mp;
    map<string, int>::iterator itr;
    int i, j, k, l, flag = 0,len, m ;
    string s = "";
    for(i = 0; i < B.size(); i++)
    {
        mp[B[i]] += 1; 
    }
    l = B[0].size();
    len = l*B.size();
    
    if(len > A.size())
    {
        return v;
    }
    for(i = 0; i < (A.size()-len +1) ; i++)
    {
        for(j = i; j < i + len; j++)
        {
            for(k = j; k < j+l; k++)
            {
                s += A[k];
            }
            if(mp.find(s) == mp.end())
            {
                flag = 1;
                s = "";
                break;
            }
            else
            {
                mp[s] -= 1;
                for(itr = mp.begin(); itr != mp.end(); itr++)
                {
                    if(itr -> second < 0 && j < i+len)
                    {
                        flag = 1;
                        break;
                    }
                }
                s = "";
            }
            j = j+l - 1;
        }
        if(flag == 0)
        {
            v.push_back(i);
        }
        flag = 0;
        mp.clear();
        for(m = 0; m < B.size(); m++)
        {
            mp[B[m]] += 1; 
        }
    }
    return v;
}
