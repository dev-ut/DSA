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
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL) return true;

        int lst=height(root->left);
        int rst=height(root->right);
        // and we havetodo it for evry node 
        int left=isBalanced(root->left);
        int right=isBalanced(root->right);

        if(abs(lst-rst)<=1 && left==true && right==true) return true;
        else return false;
    }
};