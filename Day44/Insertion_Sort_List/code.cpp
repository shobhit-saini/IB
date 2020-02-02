/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* dummy = new ListNode(-1);
    ListNode* prev = dummy, *next = NULL, *curr = A;
    while(curr != NULL)
    {
        next = curr->next;
        while(prev->next != NULL && prev->next->val < curr->val)
        {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        prev = dummy;
        curr = next;
    }
    return dummy->next;
}
