/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildcartesian(vector<int> &A, int start, int end)
{
    if(start > end)
        return NULL;
    int max = A[start];
    int index = start;
    for(int i = start+1; i <= end; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
            index = i;
        }
    }
    TreeNode* ptr = new TreeNode(max);
    ptr->left = buildcartesian(A, start, index-1);
    ptr->right = buildcartesian(A, index+1, end);
    return ptr;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode* root = buildcartesian(A, 0, A.size()-1);
    return root;
}
