// solution by @pruvi007



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
    #define ll long long int
    bool valid(TreeNode *root,ll min,ll max)
    {
        if(root==NULL)
            return true;
        if(root->val<=min || root->val>=max)
            return false;
        
        return valid(root->left,min,(root->val)) && valid(root->right,(root->val),max);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        int min = INT_MIN,max=INT_MAX;
        return valid(root,LONG_MIN,LONG_MAX);
        
    }
};