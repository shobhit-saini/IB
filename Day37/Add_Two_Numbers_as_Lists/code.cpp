/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0;
    ListNode* c = NULL, *head;
    while(A!=NULL && B!=NULL)
    {
        if(c == NULL)
        {
            c = new ListNode((A->val + B->val + carry)%10);
            carry = (A->val + B->val + carry)/10;
            head = c;
        }
        else
        {
            c->next= new ListNode((A->val + B->val + carry)%10);
            carry = (A->val + B->val + carry)/10;
            c = c->next;
        }
        A = A->next;
        B = B->next;
    }
    while(A!=NULL)
    {
        c->next= new ListNode((A->val + carry)%10);
        carry = (A->val + carry)/10;
        c = c->next;
        A = A->next;
    }
    while(B!=NULL)
    {
        c->next = new ListNode((B->val + carry)%10);
        carry = (B->val+ carry)/10;
        c = c->next;
        B = B->next;
    }
    if(carry == 1)
    {
        c->next = new ListNode((carry)%10);
    }
    return head;
}
