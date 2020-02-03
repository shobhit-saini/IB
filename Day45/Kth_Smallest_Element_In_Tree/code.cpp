/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void in(TreeNode* A, vector<int> &res)
{
    if(A != NULL)
    {
        in(A->left, res);
        res.push_back(A->val);
        in(A->right, res);
    }
}
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> res;
    in(A, res);
    return res[B-1];
}
