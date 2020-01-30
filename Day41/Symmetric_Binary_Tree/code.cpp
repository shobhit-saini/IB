/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isMirror(struct TreeNode *root1, struct TreeNode *root2) 
{ 
  
    if (root1 == NULL && root2 == NULL) 
        return 1; 
  
    if (root1 && root2 && root1->val == root2->val) 
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left); 
  
    return 0; 
}
int Solution::isSymmetric(TreeNode* A) {
    int a = isMirror(A, A);
    return  a;
    
}
/*vector<int>result;
void inorder(TreeNode* A)
{
    if(A != NULL)
    {
        inorder(A->left);
        result.push_back(A->val);
        inorder(A->right);
    }
}
int Solution::isSymmetric(TreeNode* A) {
    inorder(A);
    int i, j;
    int len  = result.size();
    
    for(i = 0; i < len/2; i++)
    {
        if(result[i] != result[len-i-1])
            return 0;
    }
    return 1;
}*/
