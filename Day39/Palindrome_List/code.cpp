/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode* ptr = A,*qtr = A,*head1,*head2,*rtr ;
    while(ptr!=NULL && ptr -> next != NULL)
    {
        ptr = ptr->next->next;
        qtr = qtr->next;
    }
    if(ptr != NULL)
        qtr = qtr -> next;
    ptr = NULL;
    rtr = qtr;
    while(rtr!=NULL)
    {
        rtr = qtr->next;
        qtr->next = ptr;
        ptr = qtr;
        qtr = rtr;
    }
    head1 = A;
    head2 = ptr;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->val != head2->val)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}
