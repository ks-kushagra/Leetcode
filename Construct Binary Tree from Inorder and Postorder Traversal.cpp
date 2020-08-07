Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
   _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-
   
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
    int findNode(vector <int> A , int i,int j, int x)
    {
        for(int k=i;k<=j;k++)
            if(A[k] == x)
                return k;
        
        return -1;
    }
    TreeNode *solve(vector <int> in , vector <int> post , int instart , int inend , int &post_curr)
    {
        if(instart > inend)
            return NULL;
        
        
        TreeNode *node = new TreeNode(post[post_curr--]);
        
        if(instart == inend)
            return node;
        
        int index = findNode(in , instart , inend , node->val);
        
        node->right = solve(in , post , index+1 , inend , post_curr);
        node->left = solve(in , post , instart ,index-1 , post_curr);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size()-1;
        TreeNode *root = solve(inorder , postorder , 0 , inorder.size()-1 , n);
        return root;
    }
};
