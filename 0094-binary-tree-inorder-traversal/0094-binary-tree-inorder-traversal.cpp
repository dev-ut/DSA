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
        // Morris traversal
        vector<int>ans;
        TreeNode* c=root;

        while(c!=NULL)
        {
            if(c->left!=NULL)
            {
             TreeNode * p=c->left;
             while(p->right!=NULL && p->right!=c)
             {
                p=p->right;
             }
             if(p->right==NULL)
             {
                // Make a Link To cureent
                p->right=c;
                c=c->left;
             }
             if(c==p->right)
             {
                p->right=NULL;
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