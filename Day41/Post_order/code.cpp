vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s1;
    vector<int> result;
    s1.push(A);
    while(!s1.empty())
    {
        A = s1.top();
        s1.pop();
        result.push_back(A->val);
        if(A->left != NULL)
        {
            s1.push(A->left);
        }
        if(A->right != NULL)
        {
            s1.push(A->right);
        }
    }
    reverse(result.begin(), result.end());
    return result;
    }
