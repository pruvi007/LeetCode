/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSYM(TreeNode *a,TreeNode *b)
    {
        if(a==NULL && b==NULL)
            return true;
        if(a && b && a->val == b->val)
        {
            return isSYM(a->left,b->right) && isSYM(a->right,b->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSYM(root,root);
        
    }
};