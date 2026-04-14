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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        //Using Stack (Iterative method)
        stack<TreeNode*>st;
        vector<int>ans;
        if(root!=NULL) st.push(root);

        while(st.size()>0)
        {
            TreeNode* x=st.top();
            st.pop();
            ans.push_back(x->val);
            if(x->right!=NULL) st.push(x->right);
            if(x->left!=NULL) st.push(x->left);
        }
        return ans;
    }
};