/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
Seen this question in a real interview before
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* temp, *start;
    multimap<int, ListNode*>mp;
    int i;
    for(i = 0; i < A.size(); i++)
    {
        ListNode* temp = A[i];
        while(temp != NULL)
        {
            mp.insert(make_pair(temp->val, temp));
            temp = temp->next;
        }
    }
    multimap<int, ListNode*>::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr++)
    {
        if(itr == mp.begin())
        {
            start = itr->second;
            temp = start;
        }
        else
        {
            temp->next = itr->second;
            temp = temp->next;
        }
    }
    return start;
}
