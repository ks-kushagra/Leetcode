Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Return false.

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________--

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
    
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        return max(height(root->left) , height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return 1;
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        int left_height = height(root->left);
        int right_height = height(root->right);
        
        if(abs(left_height - right_height)>=2)
            return 0;
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};
