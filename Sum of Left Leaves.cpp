Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode *,char>> q;
        q.push({root,'-'});
        int leaf=1;
        int ans=0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            leaf=1;
            
            if(t.first->left)
                q.push({t.first->left , 'l'}) , leaf=0;
            
            if(t.first->right)
                q.push({t.first->right,'r'}) , leaf=0;
            
            if(leaf && t.second =='l')
                ans += t.first->val;
        }
        
        return ans;
    }
};
