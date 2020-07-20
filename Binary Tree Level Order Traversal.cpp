Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode *,int> > q;
        vector<vector<int> > ans;
        if(root==NULL)
            return ans;
        
        q.push({root , 0});
        vector <int> temp;
        while(!q.empty())
        {
            auto t= q.front();
            q.pop();
            if((t.first)->left)
                q.push({(t.first)->left , t.second+1});
            if((t.first)->right)
                q.push({(t.first)->right ,t.second+1});
            
            if(t.second ==  ans.size())
            {
                ans.push_back(temp);
                ans[t.second].push_back((t.first)->val);
            }
            
            else
                ans[t.second].push_back( (t.first)->val);
            
        }
        
        return ans;
    }
};
