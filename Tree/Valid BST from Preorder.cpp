/*
Link:https://www.interviewbit.com/problems/valid-bst-from-preorder/
Problem Description

You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.



Problem Constraints
1 <= A[i] <= 106

1 <= |A| <= 105



Input Format
First and only argument is an integer array A denoting the pre-order traversal.



Output Format
Return an integer:

0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST


Example Input
Input 1:

A = [7, 7, 10, 10, 9, 5, 2, 8]


Example Output
Output 1:

 1
*/
int Solution::solve(vector<int> &A) {
    
    int i = 0, size_A = A.size(), root = -1;
    stack<int>s;
    for(i = 0; i < size_A; i++)
    {
        if(root != -1 && A[root] > A[i])
            return 0;
        while(!s.empty() && A[s.top()] < A[i])
        {
            root = s.top();
            s.pop();
        }
        s.push(i);
    }
    return 1;
}
