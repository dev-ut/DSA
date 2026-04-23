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
    if(root == nullptr) return 0;
    
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    int mxwidth = 0;
    
    while(!q.empty())
    {
        int size = q.size();
        long long left_indx  = q.front().second;
        long long right_indx = q.back().second;
        long long width = right_indx - left_indx + 1;  // +1 important
        mxwidth = max(mxwidth, (int) width);
        
        for(int i = 0; i < size; i++) 
        {
            auto p = q.front();
            TreeNode* node = p.first;
            long long indx = p.second-left_indx;
            q.pop();
            
            if(node->left != nullptr) 
                q.push({node->left, 2*indx + 1});
            if(node->right != nullptr) 
                q.push({node->right, 2*indx + 2});
        }
    }
    return mxwidth;
}
};