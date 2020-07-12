
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6


___________________________________________________________________________________________________________________________________________________________________________________________

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int,ListNode *> >s;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            s.insert({lists[i]->val , lists[i]});
        }
        ListNode *head=NULL , *p=NULL;
        
        while(s.size()>0)
        {
            auto t = *(s.begin());
            s.erase(s.begin());
            
            if(head==NULL)
            {
                head=p=t.second;
            }
            else
            {
                p->next=t.second;
                p=p->next;
            }
            
            if((t.second)->next != NULL)
            s.insert({ (t.second)->next->val , (t.second)->next});
        }
        
        return head;
    }
};
