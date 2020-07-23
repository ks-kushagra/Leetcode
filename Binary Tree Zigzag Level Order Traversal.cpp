Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
        vector <pair<TreeNode * , int> > v;
        vector<vector <int> > ans;
        if(root==NULL)
            return ans;
        v.push_back({root,0});
        int i=0;
        while(i<v.size())
        {
            auto t = v[i].first;
            int l = v[i].second;
            
            if(t->left)
                v.push_back({t->left , l+1});
            if(t->right)
                v.push_back({t->right , l+1});
            i++;
        }
        
        for(int i=0;i<v.size();)
        {
            int dir = v[i].second %2;
            int level = v[i].second;
            vector <int> temp;
            if(dir==0)
            {
                while(i<v.size() && level ==v[i].second)
                      temp.push_back((v[i++].first)->val);
                
                if(temp.size()>0)
                ans.push_back(temp);
            }
                
            else
            {
                while(i<v.size() && level == v[i].second)
                    temp.insert(temp.begin() , (v[i++].first)->val);
                
                if(temp.size()>0)
                    ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
