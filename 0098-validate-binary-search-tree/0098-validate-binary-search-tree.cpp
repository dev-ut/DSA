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
void morris(TreeNode* root,vector<int>&ans)
{
    TreeNode* curr=root;

    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            TreeNode * p=curr->left;

            while(p->right!=NULL &&  p->right != curr)
            {
                p=p->right;
            }

            // link kro 
            if(p->right==NULL)
            {
                p->right=curr;
                curr=curr->left;
            }
            // unlink kro 
            if(p->right==curr)
            {
                ans.push_back(curr->val);
                p->right=NULL;
                curr=curr->right;
            }
        }
        else
        {
            ans.push_back(curr->val);
            curr=curr->right;
        }
    }
}
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL) return false;
        vector<int>ans;
        morris(root,ans);
        // we will check ki ans mai sorted order hai ki nhi 
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]>=ans[i+1]) return false;
        }
        return true;
    }
};