/*
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
Seen this question in a real interview before
*/
struct TrieNode 
{
    struct TrieNode* children[26];
    bool isend;
};
struct TrieNode* getnode()
{
    struct TrieNode *temp = new TrieNode;
    int i;
    for(i = 0; i < 26; i++)
    {
        temp -> children[i] = NULL;
    }
    temp -> isend = 0;
    return temp;
}
void insert(struct TrieNode *root, string str)
{
    int i;
    struct TrieNode *search = root;
    for(i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if(!search->children[index])
        {
            search->children[index] = getnode();
        }
        search = search->children[index];
    }
    search->isend = 1;
}
bool search(struct TrieNode* root, string key)
{
    int i;
    struct TrieNode* search = root;
    for(i = 0; i < key.length(); i++)
    {
        int index = key[i]-'a';
        if(search->children[index])
            search = search->children[index];
        else
            return 0;
    }
    return (search->isend);
}
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
    struct TrieNode *root = getnode();
    for(i = 0; i < v.size(); i++)
    {
        insert(root, v[i]);
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
            bool result;
            result = search(root, v1[j]);
            if(result == 1)
                count++;
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
