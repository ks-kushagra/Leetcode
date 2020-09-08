Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit. 
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    
    int OR(string a , string b)
    {
        bitset<32> A(a);
        bitset<32> B(b);
        return A.to_ulong() + B.to_ulong();
    }
    
    void solve(TreeNode *root , string s , vector <string> &bin)
    {
        if(root == NULL)
             return ;
        
        if(root->left==NULL && root->right == NULL)
        {
            bin.push_back(s + to_string(root->val));
            return ;
        }
        
        solve(root->left , s + to_string(root->val)  , bin);
        solve(root->right , s +  to_string(root->val) ,bin);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector <string> bin;
        solve(root , "" , bin);
        int ans =0;
        
        for(int i=0;i<bin.size();i++)
              ans = OR(bitset<32>(ans).to_string() , bin[i]);
         
        return ans;
        
    }
};
