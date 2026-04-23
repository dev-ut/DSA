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
    vector<int> inorderTraversal(TreeNode* root) 
    {
       // morris tracersal 
       vector<int>ans;
       if(root==NULL) return ans;   
       TreeNode* c=root;

       while(c!=NULL)
       {
          if(c->left!=NULL)
          {
             TreeNode* pred=c->left;
             while(pred->right!=NULL && pred->right!=c)
             {
                pred=pred->right;
             }
             if(pred->right==NULL)
             {
                pred->right=c;
                c=c->left;
             }
             if(pred->right==c)
             {
                pred->right=NULL;
                ans.push_back(c->val);
                c=c->right;
             }
         }
          else
          {
            ans.push_back(c->val);
            c=c->right;
          }
        } 
        return ans;
    }
};