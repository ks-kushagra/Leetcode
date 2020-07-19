Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

___________________________________________________________________________________________________________________________________________________________________________________________________________________-



class Solution {
public:
    ListNode *g=NULL;
    
    int solve(ListNode *head)
    {
        int t=-1;
        if(head->next !=NULL)
            t=solve(head->next);
        
        if(t == 0)
            return 0;
        
        if(g->val != head->val)
            return 0;
        
        g=g->next;
        return 1;
    }
    
    
    bool isPalindrome(ListNode* head) {
        g=head;
        if(head==NULL || head->next == NULL)
            return 1;
        
        return solve(head);        
    }
};
