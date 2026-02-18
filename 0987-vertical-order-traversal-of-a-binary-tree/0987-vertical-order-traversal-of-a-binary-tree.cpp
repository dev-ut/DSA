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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    vector<vector<int>> fans;
    if(root == NULL) return fans;

    queue<pair<TreeNode*, pair<int,int>>> q;
    map<int, map<int, multiset<int>>> mp;

    q.push({root, {0, 0}});

    while(!q.empty())
    {
        auto x = q.front();
        q.pop();

        TreeNode* node = x.first;
        int vertical = x.second.first;
        int level = x.second.second;

        mp[vertical][level].insert(node->val);

        if(node->left)
            q.push({node->left, {vertical - 1, level + 1}});

        if(node->right)
            q.push({node->right, {vertical + 1, level + 1}});
    }

    for(auto v : mp)
    {
        vector<int> ans;
        for(auto l : v.second)
        {
            for(int val : l.second)
                ans.push_back(val);
        }
        fans.push_back(ans);
    }

    return fans;
}

};