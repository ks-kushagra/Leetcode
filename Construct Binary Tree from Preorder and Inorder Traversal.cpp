Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
___________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    int findindex(vector<int> i , int x)
    {
        for(int j=0;j<i.size();j++)
            if(x==i[j])
                return j;
        
        return -1;
    }
    TreeNode *solve(TreeNode *root , vector <int> p , vector <int> i , int instart , int inend , int &curr)
    {
        if(curr == p.size())
            return NULL;
        if(instart>inend)
            return NULL;

        int index = findindex(i,p[curr]);
        if(index==-1)
            return NULL;
        
        TreeNode *p1 = new TreeNode(p[curr++]);
        p1->left=solve(root,p,i,instart,index-1,curr);
        p1->right=solve(root , p,i,index+1,inend,curr);
        return p1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      
        TreeNode *root=NULL;
        int curr=0;
        root =solve(root , preorder,inorder,0,inorder.size()-1,curr);
        return root;
    }
};
