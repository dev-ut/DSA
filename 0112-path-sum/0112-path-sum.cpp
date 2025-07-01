
class Solution {
public:
bool preorder(TreeNode* root, int targetSum)
{
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) 
    {
         if (root->val == targetSum) return true;
         else return false;
    }
     
    // Traverse left and right subtrees
    bool leftPath = preorder(root->left, targetSum - root->val);
    bool rightPath = preorder(root->right, targetSum - root->val);   // hmne yahan yeh variable isliye bnaya hai taki hamare paas ek record rhe path ka

    // Return true if either left or right subtree has a path sum equal to targetSum
    return leftPath || rightPath;
}
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return preorder(root, targetSum);
    }
};