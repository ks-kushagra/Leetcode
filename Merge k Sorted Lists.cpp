
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
        
        __________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
        
        
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
    ListNode* mergeKLists(vector<ListNode*>& A) {
        priority_queue< pair<int,int>  , vector <pair<int,int> > , greater<pair<int,int> > > pq;
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=NULL)
                pq.push({A[i]->val , i});
        }
        
        ListNode *head =NULL,*r=NULL;
        
        if(pq.empty())
            return head;
        
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            ListNode *p = new ListNode(t.first);
            A[t.second] = A[t.second]->next;
            if(A[t.second] !=NULL)
                pq.push({A[t.second]->val , t.second});
            
            if(head == NULL)
                head =r=p;
            
            else
            {
                r->next=p;
                r=r->next;
            }
            
        }
        
        return head;
    }
};
    }
};
