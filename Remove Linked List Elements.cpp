Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    ListNode* removeElements(ListNode* head, int val) {
     
        while(head != NULL && head->val==val)
            head=head->next;
        
        if(head ==NULL)
            return head;
        
         ListNode *p=head;
 
           while(p!=NULL && p->next != NULL)
           {
               ListNode *q=p->next;
               while(q!=NULL && q->val ==val)
               {
                   q=q->next;
               }
               
               p->next=q;
               p=p->next;
           }
        
        return head;
    }
};
