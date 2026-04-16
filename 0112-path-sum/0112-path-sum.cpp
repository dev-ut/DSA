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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
       if(root==NULL) return false;
       // if its a chile leaft
       if(root->left==NULL && root->right==NULL)
       {
        if(root->val==targetSum) return true;
        else return false;
       }
       bool leftpath= hasPathSum(root->left,targetSum-root->val);
       bool rightpath= hasPathSum(root->right,targetSum-root->val);

       if(leftpath==true) return true;
       if(rightpath==true) return true;

       return false;   
    }
};