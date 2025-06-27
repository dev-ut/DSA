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
        vector<vector<int>> fans;
        // now following up with bfs
        if(root==NULL) return fans;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;  // to jb bhi hum direction chnge rnege we will mark l->r 0 and r->l 1

        while(q.size()>0)
        {
            int size=q.size();
            vector<int> ans(size);
            // ab humkoutni baar hi chlna hai jitni nodes hai us level main 
            for(int i=0;i<size;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                // check kro ki left toright hai ay right to left
                if(flag==0) // left to right
                {
                   ans[i]=temp->val;
                   if(temp->left!=NULL) q.push(temp->left);
                   if(temp->right!=NULL) q.push(temp->right);

                }
                else
                {
                    ans[size-1-i]=temp->val;
                   if(temp->left!=NULL) q.push(temp->left);
                   if(temp->right!=NULL) q.push(temp->right);
                }
            }
            if(flag==0) flag=1;
            else flag=0;
            fans.push_back(ans);
        }
        return fans;
    }
};