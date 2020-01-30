/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack <TreeNode*>s;
    TreeNode* temp;
    vector<int> result;
    while(1)
    {
        if(A != NULL)
        {
            s.push(A);
            A = A->left;
        }
        else
        {
            if(s.empty())
                break;
            A = s.top();
            s.pop();
            result.push_back(A->val);
            A = A->right;
        }
    }
    return result;
}
