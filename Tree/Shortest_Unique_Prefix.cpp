/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 
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
string pre(struct TrieNode* root, string str)
{
    string str1="";
    int i, j;
    int index;
    struct TrieNode* crawl = root;
    struct TrieNode* crawl1 = root;
    int count = 0;
    for(i = 0; i < str.length(); i++)
    {
        count = 0;
        for(j = 0; j < 26; j++) 
        {
            if(crawl->children[j] != NULL)
            {
                count++;
            }
        }
        if(count > 1)
        {
            crawl1 = crawl;
        }
        index = str[i] - 'a';
        crawl = crawl -> children[index]; 
    }
    crawl = root;
    for(i = 0; i < str.length(); i++)
    {
        str1 += str[i];
        index = str[i] - 'a';
        if(crawl == crawl1)
        {
            break;
        }
        crawl = crawl->children[index];
    }
    return str1;
}
vector<string> Solution::prefix(vector<string> &A) {
    int i;
    string str;
    vector<string> result;
    struct TrieNode *root = getnode();
    for(i = 0; i < A.size(); i++)
    {
        insert(root, A[i]);
    }
    for(i = 0; i < A.size(); i++)
    {
        str = pre(root, A[i]);
        result.push_back(str);
    }
    return result;
}
