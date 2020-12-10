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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //最近公共祖先问题,法一：遍历2次，得到两个序列；法二：遍历1次，同时比较，递归左子树或右子树。
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
