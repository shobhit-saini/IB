/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
Seen this question in a real interview before
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
/*int find_path(TreeNode* A, int pathlen, int B, int* arr, vector<vector<int>>&result)
{
    static int j = 0;
    int i, sum = 0;
    if(A == NULL)
        return 0;
    arr[pathlen] = A->val;
    pathlen++;
    if(A->left == NULL && A->right == NULL)
        {
            for(i = 0; i < pathlen; i++)
            {
                sum = sum+arr[i];
            }
            if(sum == B)
            {
                for(i = 0; i < pathlen; i++)
                {
                    result[j].push_back(arr[i]);
                }
                j++;
            }
        }
    else
    {
        find_path(A->left, pathlen, B, arr, result);
        find_path(A->right, pathlen, B, arr, result);
    }
    return j;
    
}
int maxDepth(TreeNode* A) {
    if(A == NULL)
    {
        return 0;
    }
    int dl = maxDepth(A->left);
    int dr = maxDepth(A->right);
    if(dl < dr)
    {
        return dr+1;
    }
    else
        return dl+1;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    int len = maxDepth(A);
    int arr[len];
    vector<vector<int>>result(100000);
    int j = find_path(A, 0, B, arr, result);
    vector<vector<int>> res(j);
    cout<<j;
    for(int i = 0; i < j; i++)
    {
        res[i] = result[i];
    }
    return res;
}*/


void find_path(TreeNode* A, int B, vector<vector<int>>&result, vector<int> &curr, int sum)
{
    if(A == NULL)
        return;
    curr.push_back(A->val);
    sum = sum + A->val;
    if(A->left == NULL && A->right == NULL && B == sum)
    {
        result.push_back(curr);
    }
    find_path(A->left, B, result, curr, sum);
    find_path(A->right, B, result, curr, sum);
    curr.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> result;
    vector<int> curr;
    int sum = 0;
    find_path(A, B, result, curr, sum);
    return result;
}
