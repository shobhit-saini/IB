/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    stack<TreeNode*> s;
    TreeNode* ptr = A;
    if(ptr == NULL)
        return ptr;
    s.push(ptr);
    while(!s.empty())
    {
        ptr = s.top();
        s.pop();
        if(ptr->right != NULL)
        {
            s.push(ptr->right);
        }
        if(ptr->left != NULL)
        {
            s.push(ptr->left);
        }
        if(!s.empty())
        {
            ptr->right = s.top();
        }
        ptr->left = NULL;
    }
    return A;
}
