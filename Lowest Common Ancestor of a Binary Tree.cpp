Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int inorder(TreeNode *root , TreeNode *x)
    {
        if(root == NULL)
            return 0;
        if(root == x)
            return 1;
        
        return (inorder(root->left ,x ) || inorder(root->right ,x));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL || (root->left == NULL && root->right == NULL))
            return root;
        
        int left_p = inorder(root->left,p);
        int left_q = inorder(root->left , q);
        int right_p = inorder(root->right , p);
        int right_q =inorder(root->right , q);
        
        //If both are on left
        if(left_p && left_q)
            return lowestCommonAncestor(root->left , p ,q);
        
        //if both are on right
        if(right_p && right_q)
            return lowestCommonAncestor(root->right , p,q);
        
        //if one is on left and one is on right
           return root;
    }
};
