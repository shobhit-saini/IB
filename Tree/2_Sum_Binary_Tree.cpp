/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0
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
 void inorder(TreeNode* A, map<int, int>&m, int k, int *a)
 {
    if(A == NULL)
    {
       return ; 
    }
    inorder(A->left, m, k, a);
    if(m.find(A->val) != m.end())
    {
        *a = 1;
    }
    m[k-A->val] = A->val;
    inorder(A->right, m, k, a);
 }
int Solution::t2Sum(TreeNode* A, int B) {
    map<int, int>m;
    int a = 0;
    inorder(A, m, B, &a);
    if(a == 1)
        return 1;
    else
        return 0;
}
