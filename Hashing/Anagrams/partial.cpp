/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4.
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group.
*/
template <typename Map>
bool key_compare (Map const &lhs, Map const &rhs) {

    auto pred = [] (decltype(*lhs.begin()) a, decltype(a) b)
                   { return a.first == b.first; };

    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(), rhs.begin(), pred);
}
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    multimap<char, int> mp, mp1;
    map<int, int> m;
    int i, j, k, flag = 0;
    vector<int> v;
    vector<vector<int>> res;
    for(i = 0; i < A.size(); i++)
    {
        if(m.find(i+1) == m.end())
        {
            v.push_back(i+1);
            m[i+1] = 1;
        }
        else
        {
            continue;
        }
        for(j = 0; j < A[i].size(); j++)
        {
            mp.insert(make_pair(A[i][j],1));
        }
        for(k = i+1; k < A.size(); k++)
        {
            for(j = 0; j < A[k].size(); j++)
            {
                mp1.insert(make_pair(A[k][j], 1));
            }
            if(key_compare(mp, mp1))
            {
                if(m.find(k+1) == m.end())
                {
                    v.push_back(k+1);
                    m[k+1] = 1;
                }
            }
            mp1.clear();
        }
        res.push_back(v);
        v.clear();
        mp.clear();
    }
    return res;
}
