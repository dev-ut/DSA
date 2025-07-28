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
int ans=0;

    // Normal depth jaisa hi function, lekin value match wali condition ke sath
    int dfs(TreeNode* root) 
    {
        if (!root) return 0;

        // Left aur right depth nikaal lo
        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = 0, rightPath = 0;

        // Sirf tabhi left/right path banao jab value same ho
        if (root->left && root->left->val == root->val) {
            leftPath = left + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightPath = right + 1;
        }

        // Total max path update karo
        ans = max(ans, leftPath + rightPath);

        // Jaise depth return karte ho, waise hi max(leftPath, rightPath) return karo
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};