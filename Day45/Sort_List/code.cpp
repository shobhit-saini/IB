
int mid(ListNode* A)
{
    int count = 0;
    while(A != NULL)
    {
        A = A->next;
        count++;
    }
    return count;
}
ListNode* Merge(ListNode* s1, ListNode* s2)
{
    ListNode* dummy = NULL;
    ListNode* ptr = dummy;
    if(s1 == NULL)
        return s2;
    if(s2 == NULL)
        return s1;
    if(s1 -> val <= s2 -> val)
    {
        dummy = s1;
        s1 = s1 -> next;
    }
    else
    {
        dummy = s2;
        s2 = s2 -> next;
    }
    ptr = dummy;
    while(s1 != NULL && s2 != NULL)
    {
        if(s1->val < s2->val)
        {
            ptr->next = s1;
            s1 = s1->next;
        }
        else
        {
            ptr->next = s2;
            s2 = s2->next;
        }
        ptr = ptr->next;
    }
    while(s1 != NULL)
    {
        ptr->next = s1;
        s1 = s1->next;
        ptr = ptr->next;
    }
    while(s2 != NULL)
    {
        ptr->next = s2;
        s2 = s2->next;
        ptr = ptr->next;
    }
    return dummy;
}
ListNode* Solution::sortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* s1, *s2, *s = A, *m, *p, *head = A;
    int i = 1, count;
    if(A == NULL || A-> next == NULL)
        return A;
    else
    {
        count = mid(A);
        while(i != count/2)
        {
            A = A->next;
            i++;
        }
        p = A->next;
        A->next = NULL;
        /**/ s1 = sortList(head);
        s2 = sortList(p);
        s =Merge(s1,s2);
        return s;
    }
        
    
}
