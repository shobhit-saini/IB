/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* A) {
    if(A == NULL)
    {
        return 0;
    }
    int dl = maxDepth(A->left);
    int dr = maxDepth(A->right);
    if(dl < dr)
    {
        return dr+1;
    }
    else
        return dl+1;
}
