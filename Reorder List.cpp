Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
______________________________________________________________________________________________________________________________________________________________________________________________________________

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
    void reorderList(ListNode* head) {
       
       vector <ListNode *> v;
       if(head == NULL || head->next == NULL)
           return ;
        
        ListNode *p = head;
        
        while(p!=NULL)
            v.push_back(p),p=p->next;
        
        int i=0,j=v.size()-1;
        while(i<j)
        {
            v[i++]->next=v[j];
            if(i == j){
                v[i]->next=NULL;
                break;
            }
            v[j--]->next=v[i];
            
                if(i == j){
                v[i]->next=NULL;
                break;
            }
        }
        
        head = v[0];
    }
};
