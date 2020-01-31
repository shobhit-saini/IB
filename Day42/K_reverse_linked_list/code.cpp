/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* current = A, *prev = NULL, *next = NULL;
    int count = 0;
    while(current != NULL && count < B)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    if(next != NULL)
    {
        A->next = reverseList(next, B);
    }
    return prev;
}
