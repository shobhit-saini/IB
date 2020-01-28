/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* string str = "";
void Inorder(TreeNode* A)
 {
     if(A != NULL)
     {
        Inorder(A->left);
        str = str + to_string(A -> val);
        Inorder(A->right);
     }
 }
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    string str1 = "", str2 = "";
    Inorder(A);
    str1 = str;
    str = "";
    Inorder(B);
    str2 = str;
    if(str1.compare(str2) == 0)
    {
        return 1;
    }
    return 0;
}*/

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if(A==NULL && B==NULL)
        return 1;
   
    if(A==NULL || B==NULL)
        return 0;

    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right) && A->val==B->val;
 
}
