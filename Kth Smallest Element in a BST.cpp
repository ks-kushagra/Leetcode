Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

Constraints:

The number of elements of the BST is between 1 to 10^4.

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

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
    int nodes(TreeNode *A)
    {
        if(A==NULL)
            return 0;
        if(A->left == NULL && A->right == NULL)
            return 1;
        
        return 1 + nodes(A->left)+nodes(A->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int rank = nodes(root->left)+1;
        
        if(k==rank)
            return root->val;
        else if(k>rank)
            return kthSmallest(root->right,k-rank);
        else
            return kthSmallest(root->left,k);
    }
};
