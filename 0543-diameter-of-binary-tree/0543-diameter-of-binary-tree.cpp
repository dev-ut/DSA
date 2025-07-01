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
int maxpath=0;
int height (TreeNode* root)
        {
            if(root==NULL) return 0;
            return 1+max(height(root->left),height(root->right));
        }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        
        if(root==NULL) return 0;

        int path= height(root->left)+ height(root->right);  // including current root node 

        maxpath=max(path,maxpath);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxpath;
    }
};