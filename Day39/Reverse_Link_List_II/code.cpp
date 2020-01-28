/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* ptr1=A, *qtr2 = A, *ptr2, *qtr1, *ptr, *qtr, *rtr = A;
    int i = 1, j = 1;
    if(A->next == NULL)
    {
        return A;
    }
    while(i < B-1)
    {
        ptr1 = ptr1->next;
        i++;
    }
    while(j < C)
    {
        qtr2 = qtr2->next;
        j++;
    }
    if(B == 1)
    {
        ptr1 = NULL;
        ptr2 = A;
    }
    else
        ptr2 = ptr1->next;
    qtr1 = qtr2->next;
   // cout << ptr1->val << ":" << qtr1->val;
    //cout << ptr2->val << ":" << qtr2->val<< ":";
    ptr = NULL, qtr = ptr2;
    while(rtr != qtr1)
    {
        rtr = qtr -> next;
        qtr->next = ptr;
        ptr = qtr;
        qtr = rtr;
    }
    if(B != 1)
        ptr1->next = qtr2;
    else
        A = qtr2;
    ptr2->next = qtr1;
    return A;
}
