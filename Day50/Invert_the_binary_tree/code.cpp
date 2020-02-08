/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    TreeNode* temp;
    if(A == NULL)
        return A;
    if(A->left == NULL && A->right == NULL)
        return A;
    else
    {
        temp = A->right;
        A->right = invertTree(A->left);
        A->left = invertTree(temp);
        return A;
    }
}
