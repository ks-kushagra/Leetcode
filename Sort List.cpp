Sort a linked list using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    void swap(ListNode *p , ListNode *q)
    {
        int t = p->val;
        p->val= q->val;
        q->val =t;
    }
    
    ListNode* sortList(ListNode* head) {
       
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *p=head;
        while(p!=NULL)
        {
            ListNode *q =p->next;
            while(q!=NULL)
            {
                if(p->val > q->val)
                    swap(p,q);
                
                q=q->next;
            }
            
            p=p->next;
        }
        
        return head;
    }
};
