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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
       vector<vector<int>>fans;
       if(root==NULL) return fans;
       queue<TreeNode*>q;
       q.push(root);
       int flag=0;

       while(q.size()>0)
       {
        int size=q.size();
        vector<int>ans(size);

        for(int i=0;i<size;i++)
        {
            TreeNode* x=q.front();
            q.pop();

            if(flag==0) // left to right normal 
            {
              ans[i]=x->val;
              if(x->left!=NULL) q.push(x->left);
              if(x->right!=NULL) q.push(x->right);
              
            }
            else
            {
             ans[size-1-i]=x->val;   // i keeep value dynaic
              if(x->left!=NULL) q.push(x->left);
              if(x->right!=NULL) q.push(x->right);
              
            }
        }
        if(flag==0) flag=1;
        else flag=0;
        fans.push_back(ans);
       }
       return fans;
}
};