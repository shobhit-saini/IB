/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* B;
    B = A;
    while(B->next != NULL)
    {
        if(B->val == B->next->val)
        {
            B->next = B->next->next;
        }
        else
        {
            B = B->next;
        }
    }
    return A;
}
