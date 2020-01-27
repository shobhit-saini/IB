/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* ptr = A,*qtr = A;
    int flag = 0;
    while(ptr!=NULL&& ptr -> next != NULL && qtr->next!=NULL)
    {
        ptr = ptr->next->next;
        qtr = qtr->next;
        if(ptr == qtr)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        return NULL;
    }
    qtr = A;
    while(ptr != qtr)
    {
        qtr = qtr->next;
        ptr = ptr->next;
    }
    return ptr;
}
