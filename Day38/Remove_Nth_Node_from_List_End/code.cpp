/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int i = 0, size = 0;
    ListNode* temp = A;
    while(temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    if(size == 1)
    {
        A= NULL;
        return A;
    }
    temp = A;
    if(size < B)
    {
        A = A->next;
        return A;
    }
    if(size-B == 0)
    {
        A = A->next;
        return A;
    }
    for(i = 0; i < size- B-1 ; i++)
    {
        temp = temp->next;
    }
    
    temp ->next = temp->next->next;
    return A;
}
