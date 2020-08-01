Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node,
just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 _____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node *nextPtr(Node *root)
    {
        Node *temp = root->next;
        while(temp!=NULL)
        {
            if(temp->left)
                return temp->left;
            if(temp->right)
                return temp->right;
            
            temp = temp->next;
        }
        
        return NULL;
    }
    Node* connect(Node* root) {
        if(root== NULL || ( root->left == NULL && root->right == NULL))
            return root;
        
        Node *p=root;
        while(p!=NULL)
        {
            Node *q = p;
            while(q!=NULL){
            if(q->left)
            {
                if(q->right)
                    q->left->next = q->right;
                
                else
                    q->left->next = nextPtr(q);
            }
            
            if(q->right)
               q->right->next = nextPtr(q);     
                
            q=q->next;
        }
            
        if(p->left)
            p=p->left;
        else if(p->right)
            p=p->right;
        else
          p=p->next;
                
        }
        
        return root;
    }
};
