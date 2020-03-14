/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void pathfind(TreeNode* A, vector<vector<int>> &result, vector<int> &v, int temp)
{
    if(A == NULL)
        return;
    v.push_back(A->val);
    if(A -> val == temp)
    {
        result.push_back(v);
    }
    pathfind(A->left, result, v, temp);
    pathfind(A->right, result, v,temp);
    v.pop_back();
}
int Solution::lca(TreeNode* A, int B, int C) {
    vector<vector<int>> result;
    vector<int> v;
    int size, res, j;
    pathfind(A, result, v, B);
    pathfind(A, result, v, C);
    if(result.size() < 2)
        return -1;
    size = (result[0].size() <= result[1].size())? result[0].size(): result[1].size(); 
    for(j = 0; j < size; j++)
    {
        if(result[0][j] == result[1][j])
            res = result[0][j];
    }
    return res;
}
