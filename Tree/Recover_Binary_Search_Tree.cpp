/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 
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
 TreeNode* predecessor(TreeNode* temp)
{
    TreeNode* c = temp->left;
    while(c->right != temp && c->right != NULL)
    {
        c = c -> right;
    }
    return c;
}
vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode* pre, *temp = A;
    int i;
        vector<int> result;
        vector<int> res;
        while(temp != NULL)
        {
            if(temp -> left == NULL)
            {
                //cout << temp->val;
                result.push_back(temp -> val);
                temp = temp->right;
            }
            else
            {
                pre = predecessor(temp);
                if(pre -> right == NULL)
                {
                    pre -> right = temp;
                    temp = temp->left;
                }
                else
                {
                    pre -> right = NULL;
                   // cout << temp->val;
                    result.push_back(temp->val);
                    temp = temp -> right;
                }
            }
        }

            int first, middle, last = -1, flag = 0; 
            for(i = 1; i < result.size(); i++)
            {
                if(result[i-1] > result[i])
                {
                    if(flag == 0)
                    {
                        first = i-1;
                        middle = i;
                        flag = 1;
                    }
                    else
                    {
                        last = i;
                    }
                }
            }
            if(last == -1)
            {
                res.push_back(result[middle]);
                res.push_back(result[first]);
            }
            else
            {
                res.push_back(result[last]);
                res.push_back(result[first]);
            }
            return res;
}
