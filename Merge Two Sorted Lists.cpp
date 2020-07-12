Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


_________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        ListNode *p=NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        while(l1!=NULL && l2 != NULL)
        {
            ListNode *r;
            if(l1->val < l2->val)
            {
                r=l1; 
                l1=l1->next;
            }
            
            else 
            {
                r=l2;
                l2=l2->next;
            }
            
            if(p==NULL)
             head=p=r;
                
            else{
                 p->next=r;
                 p=p->next;
                }
            
        }
        
        if(l1 != NULL)
            p->next = l1;
         
        if(l2 != NULL)
            p->next=l2;
        
        return head;
    }
};
