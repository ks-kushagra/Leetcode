Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

________________________________________________________________________________________________________________________________________________________________________________________________________________

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *p=root;
        while(p!=NULL)
            s.push(p),p=p->left;
        while(!s.empty())
        {
            TreeNode *q=s.top();
            s.pop();
            ans.push_back(q->val);
            if(q->right)
            {
                s.push(q->right),q=q->right;
                while(q->left !=NULL)
                    s.push(q->left),q=q->left;
            }
        }
        
        return ans;
    }
};
