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
    int level(TreeNode* root, int &maxpath) {
        if(root == nullptr) return 0;

        // Left aur right subtree ka height nikal lo
        int left = level(root->left, maxpath);
        int right = level(root->right, maxpath);

        // Har node par max path check kro (diameter = left + right)
        maxpath = max(maxpath, left + right);

        // Wapas height return kro is node ke liye
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxpath = 0;
        level(root, maxpath);
        return maxpath;
    }
};
