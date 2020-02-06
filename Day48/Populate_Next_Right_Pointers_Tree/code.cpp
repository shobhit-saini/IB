/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    int flag = 0, flag1 = 0;
    TreeLinkNode* ptr;
    q.push(A);
    A->next = NULL;
    while(!q.empty())
    {
        ptr = q.front();
        q.pop();
        if(ptr->left != NULL)
        {
            q.push(ptr->left);
            flag = 1;
        }
        if(ptr->right != NULL)
        {
            q.push(ptr->right);
            ptr->right->next = NULL;
            flag1 = 1;
            if(flag == 1)
                ptr->left ->next = ptr->right; 
        }
        if(flag1 == 0)
            ptr->left->next = NULL;
        flag = 0; flag1 = 0;
    }
}
