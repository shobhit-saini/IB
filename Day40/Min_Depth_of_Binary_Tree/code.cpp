/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A->left == NULL && A->right == NULL)
    {
        return 1;
    }
    int hl, hr;
    if(A->left != NULL)
         hl = minDepth(A->left)+1;
    if(A->right != NULL)
         hr = minDepth(A->right)+1;
    if(hl < hr)
    {
        return hl;
    }
    else
        return hr;
}
