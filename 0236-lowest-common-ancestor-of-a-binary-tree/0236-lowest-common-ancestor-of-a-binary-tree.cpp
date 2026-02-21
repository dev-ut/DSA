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
TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL) return NULL;

    if(root->val==p->val || root->val==q->val) // at any side 
    {
       return root;
    }

    TreeNode* left=solve(root->left,p,q);
    TreeNode* right=solve(root->right,p,q);

    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;  // or ye whi root hai jispe dono values ake rooki hai .
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
          return solve(root,p,q); 
    }
};