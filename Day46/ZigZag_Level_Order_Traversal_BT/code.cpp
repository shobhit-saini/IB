/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int size(TreeNode* A)
{
    if(A == NULL)
        return 0;
    int hl = size(A->left);
    int hr = size(A->right);
    if(hl < hr)
    {
        return hr+1;
    }
    else
    {
        return hl+1;
    }
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    int a = size(A);
    vector<vector<int>> result(a);
    queue<TreeNode*> q;
    q.push(A);
    TreeNode* ptr = A, *x;
    int count1 = 1, count2 = 1, i = 0, j;
    while(count2 != 0)
    {
        count2 = 0;
        while(count1 != 0)
        {
            count1--;
            ptr = q.front();
            q.pop();
            result[i].push_back(ptr->val);
            if(ptr->left != NULL)
            {
                q.push(ptr->left);
                count2++;
            }
            if(ptr->right != NULL)
            {
                q.push(ptr->right);
                count2++;
            }
        }
        i++;
        count1 = count2;
    }
    for(j = 0; j < i; j++)
    {
        if(j%2 == 1)
        {
            reverse(result[j].begin(), result[j].end());
        }
    }
    return result;
}
