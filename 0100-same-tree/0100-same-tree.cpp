
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL && q==NULL) return true;
        if(p!=NULL &&q==NULL || p==NULL && q!=NULL) return false;
        if(p->val!=q->val) return false;

        bool leftsubtree= isSameTree(p->left,q->left);
        if(leftsubtree==false) return false;

        bool rightsubtree= isSameTree(p->right,q->right);
        if(rightsubtree==false) return false;

        return true;
    }
};