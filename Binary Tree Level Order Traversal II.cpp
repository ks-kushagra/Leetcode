Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

______________________________________________________________________________________________________________________________________________________________________________________________________

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     vector <pair<TreeNode *,int> > v;
        vector <vector <int> > ans;
        
        if(root == NULL)
            return ans;
        v.push_back({root,0});
        
        int flag=1;
        
        int i=0;
        
        while(flag)
        {
            flag=0;
            auto p = v[i];
            if(p.first->left)
            {
                flag = 1;
                v.push_back({p.first->left , p.second+1});
            }
            
            if(p.first->right)
            {
                  flag=1;
                  v.push_back({p.first->right , p.second + 1});
            }
            
            if(i < v.size()-1)
                flag=1;
            
            
            i++;
        }
        
        
        i=0;
        while( i < v.size())
        {
            vector <int> t;
            t.push_back(v[i].first->val);
            
            int level =v[i].second;
            
            int j =i+1;
            while( j < v.size() && v[j].second == level)
                   t.push_back(v[j++].first->val);
            
            i=j;
            ans.insert(ans.begin() , t);
        }
        
        return ans;
        

    }
};
