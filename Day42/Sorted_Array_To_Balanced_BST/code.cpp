/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* fun(const vector<int> &B, int low, int high)
{
    if(low > high)
    {
        return NULL;
    }
    int mid = (low +  high)/2;
    TreeNode* ptr = new TreeNode(B[mid]);
    ptr -> left = fun(B, low , mid-1);
    ptr->right = fun(B, mid+1, high);
    return ptr;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode* head;
    head = fun(A, 0, A.size()- 1);
    return head;
}
