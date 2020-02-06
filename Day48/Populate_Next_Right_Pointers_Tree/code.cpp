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
    int count2 = 1, count1 = 1;
    TreeLinkNode* ptr;
    q.push(A);
    while(count2 != 0)
    {
        count2 = 0;
        while(count1 != 0 )
        {
            count1--;
            ptr = q.front();
            q.pop();
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
            if(count1 > 0)
                ptr->next = q.front(); 
        }
        count1 = count2;
    }
}
