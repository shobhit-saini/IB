/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL)
    {
        return NULL;
    }
    ListNode* temp = A,*ptr, *qtr, *itr;
    ListNode* ptrn = new ListNode(-1);
    ptr = ptrn;
    ListNode* qtrn = new ListNode(-1);
    qtr = qtrn;
    itr = A;
    while(itr != NULL)
    {
        if(itr->val < B)
        {
            ptr->next = itr;
            ptr = itr;
        }
        else if(itr -> val >= B)
        {
            qtr->next = itr;
            qtr = itr;
    
        }
        itr = itr->next;
    }
    qtr->next = NULL;
    ptr->next = qtrn->next;
    return ptrn->next;
    /*int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp =  A;
    while(temp != NULL)
    {
        if(temp->val == B)
        {
            break;
        }
        prev = temp;
        prev1 = temp;
        temp = temp->next;
    }
    cout << temp -> val;
    next = temp->next;
    while(temp1 != NULL)
    {
        if(temp1 == prev1)
        {
            while(temp1 != next)
            {
                temp1 = temp1->next;
            }
            temp1 = temp1->next;
        }
        else if(temp1->val < B)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            prev->next = temp2;
            temp2->next = temp;
            prev = temp2;
        }
        else if(temp1->val > B)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            temp->next = temp2;
            next = temp2;
        }
    }*/
}
