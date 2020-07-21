Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


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
    TreeNode *mirror(TreeNode *root)
    {
        if(root == NULL || (root->left ==NULL && root->right==NULL))
            return root;
        
        TreeNode *p = new TreeNode(root->val);
         p->left=mirror(root->right);
        p->right = mirror(root->left);
        
        return p;
    }

    int isSame(TreeNode *a , TreeNode *b)
    {
        if(a==NULL && b==NULL)
            return 1;
        
        if(a!=NULL && b==NULL)
            return 0;
        
        if(a==NULL && b!=NULL)
            return 0;
        
        if(a->val != b->val)
            return 0;
        
        return isSame(a->left,b->left) && isSame(a->right,b->right);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left ==NULL && root->right==NULL))
            return 1;
        
        TreeNode *p = mirror(root);
        
        return isSame(root,p);
    }
};
