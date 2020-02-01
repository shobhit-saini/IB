/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int fun(TreeNode* A)
{
    if(A == NULL)
        return 0;
    int dl = fun(A->left);
    int dr = fun(A->right);
    if(dl == -1 || dr == -1)
    {
        return -1;
    }
    if(abs(dr-dl) > 1)
            return -1;
    if(dl < dr)
    {
        
        return dr+1;
    }
    if(dl >= dr)
    {
        return dl+1;
    }
}
int Solution::isBalanced(TreeNode* A) {
    int res = fun(A);
    if(res == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
