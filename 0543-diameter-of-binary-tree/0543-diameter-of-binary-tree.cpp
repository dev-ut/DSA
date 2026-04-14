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
int mxdepth=0;
int height(TreeNode* root)
{
   if(root==NULL) return 0;
   return 1+ max(height(root->left),height(root->right));
}
int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL) return 0;
        // diameter=sum of max height of lmt and rmt
        int depth=height(root->left)+height(root->right);

        // store the values 
        mxdepth=max(mxdepth,depth);
        // since we have to visit every node call aminfn within main fn 

        int lst=diameterOfBinaryTree(root->left);
        int rst= diameterOfBinaryTree(root->right);

        return mxdepth;
    }
};