/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL)
        return A;
    if(A->val != A->next->val)
    {
        A->next = deleteDuplicates(A->next);
        return A;
    }
    ListNode* tracker = A;
    while(tracker != NULL && tracker->val == A->val)
    {
        tracker = tracker->next;
    }
    return deleteDuplicates(tracker);
   /* ListNode* ptr = A, *qtr, *rtr;
    if(A->next == NULL)
    {
        return A;
    }
    qtr = ptr->next;
    rtr = qtr->next;
    while(rtr != NULL && rtr->next !=NULL)
    {
        while(1)
        {
            if(qtr!=NULL&&ptr->val == qtr->val)
            {
                while(qtr!=NULL && ptr->val == qtr->val)
                {
                    qtr = qtr->next;
                }
                if(qtr == NULL)
                {
                    return NULL;
                }
                ptr = qtr;
                qtr = ptr->next;
                if(qtr!=NULL)
                {
                    rtr  = qtr->next;
                }
                else
                {
                    rtr = NULL;
                }
            }
            else
            {
                break;
            }
        }
    }
    A = ptr;
    while(rtr!= NULL && rtr->next!=NULL)
    {
        if(qtr->val == rtr->val)
        {
            while(rtr != NULL && rtr->val == qtr->val)
            {
                rtr = rtr->next;
            }
            ptr->next = rtr;
            qtr = ptr->next;
            rtr = qtr->next;
        }
        else
        {
            ptr = ptr->next;
            qtr = qtr->next;
            rtr = rtr->next;
        }
    }
    return A;*/
}
