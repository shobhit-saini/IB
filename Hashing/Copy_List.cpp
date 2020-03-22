/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

Seen this question in a real interview before
*/
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    vector<RandomListNode*>v;
    RandomListNode *temp = A, *ptr;
    while(temp != NULL)
    {
        v.push_back(temp -> random);
        temp = temp -> next;
    }
    RandomListNode *head = NULL, *qtr, *temp1 = A;
    temp = head;
    while(temp1 != NULL)
    {
        if(head == NULL)
        {
            head = new RandomListNode(temp1 -> label);
            temp1 -> random = head;
            temp = head;
        }
        else
        {
            qtr = new RandomListNode(temp1 -> label);
            temp -> next = qtr;
            temp = qtr;
            temp1 -> random = qtr;
        }
        temp1 = temp1 -> next;
    }
    temp -> next = NULL;
    temp = head;
    int i = 0;
    while(temp != NULL)
    {
        if(v[i] == NULL)
        {
            temp -> random = NULL;
        }
        else
            temp -> random = v[i] -> random;
        i++;
        temp = temp -> next;
    }
    return head;
}
