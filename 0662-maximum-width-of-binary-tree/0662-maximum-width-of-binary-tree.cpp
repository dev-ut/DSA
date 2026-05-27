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
    int widthOfBinaryTree(TreeNode* root) 
    {
    if(root==NULL) return 0;
    queue<pair<TreeNode* ,int>>q;
    int mw=0;
    q.push({root,0});

    while(q.size()>0)
    {
        int size=q.size();
        long long left_indx=q.front().second;
        long long rt_indx= q.back().second;
        int width= rt_indx-left_indx+1;
        
        mw=max(mw,width);

        for(int i=0;i<size;i++)
        {
            auto p=q.front();
            TreeNode* node=p.first;
            long long indx=p.second-left_indx;
            q.pop();

            if(node->left!=NULL) q.push({node->left,2*indx+1});

            if(node->right!=NULL) q.push({node->right,2*indx+2});
        }
    }
    return mw;

    }
};