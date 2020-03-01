/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void fun_sum(TreeNode* A, string s, int *sum)
{
    if(A == NULL)
        return;
    s += to_string(A->val);
    if(A -> left == NULL && A->right == NULL)
    {
        int res = 0;
        for (int j = 0; j < s.length(); j++) 
            res = (res*10 + (int)s[j] - '0') % 1003;
        *sum = (*sum + res) % 1003;
    }
    fun_sum(A->left, s, sum);
    fun_sum(A->right,s, sum);
}
int Solution::sumNumbers(TreeNode* A) {
    string s; int sum;
    fun_sum(A, s, &sum);
    return sum;
}
