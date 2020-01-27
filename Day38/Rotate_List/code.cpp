/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int size = 0, i;
    ListNode* temp = A, *end, *prev;
    while(temp != NULL)
    {
        size++;
        end = temp;
        temp = temp->next;
    }
    B=B%size;
    if(B == 0)
    {
        return A;
    }
    temp = A;
    for(i = 0; i < size- B ; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    end -> next = A;
    A = temp;
    return A;
    
    
}
