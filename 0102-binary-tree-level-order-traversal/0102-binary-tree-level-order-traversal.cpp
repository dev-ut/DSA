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
int level(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}

void fill(TreeNode* root,vector<vector<int>> &fans,int indx )
{
    if(root==NULL) return ;
    fans[indx].push_back(root->val);
    fill(root->left,fans,indx+1);
    fill(root->right,fans,indx+1);
}

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>fans;
       int n=level(root);
       for(int i=1;i<=n;i++)
       {
           vector<int> ans;
           fans.push_back(ans);     // khali vector abhi ek liye nas m push abck kr do
       }
       fill(root,fans,0);
        return fans;
    }
};