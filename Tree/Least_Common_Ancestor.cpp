/*
Link:https://www.interviewbit.com/problems/least-common-ancestor/
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
 bool elementChecker(TreeNode* A, int ele)
 {
    if(A == NULL)
        return false;
    if(A->val == ele)
        return true;
    return elementChecker(A->left, ele) || elementChecker(A->right, ele);
 }
 int lcaUtils(TreeNode* A, int B, int C)
 {
    if(A == NULL)
        return -1;
    if(A->val == B || A->val == C)
        return A->val;
    int left = lcaUtils(A->left, B, C);
    int right = lcaUtils(A->right, B, C);
    if(left != -1 && right != -1)
        return A->val;
    else if(left != -1 && right == -1)
        return left;
    else if(left == -1 && right != -1)
        return right;
    else
        return -1;
 }
int Solution::lca(TreeNode* A, int B, int C) {
    
    if(elementChecker(A, B) && elementChecker(A, C))
    {
        return lcaUtils(A, B, C);
    }
    return -1;
}
