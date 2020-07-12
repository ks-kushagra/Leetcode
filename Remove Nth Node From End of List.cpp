Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.
_____________________________________________________________________________________________________________________________________________________________________________________________________________


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode *A)
    {
        int len=0;
        while(A != NULL)
        {
            A=A->next;
            len++;
        }
        
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(n==len)
            return head->next;
        
        int k = len - n-1;
        ListNode *p= head;
        while(k > 0)
        {
            p=p->next;
            k--;
        }
        p->next = p->next->next;
        
        return head;
    }
};
