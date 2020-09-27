/*
   Author: litang
   Description: 
   Since: 2020/09/25
          09:43:32
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *build(int inL, int inR, int postL, int postR, const vector<int> &in, const vector<int> &post)
    {
        if (inL > inR || postL > postR)
            return NULL;
        auto root = new TreeNode(post[postR]);
        int k = inL;
        for (; in[k] != post[postR]; ++k)
            ;
        int num_left = k - inL, num_right = inR - k;
        if (num_left > 0)
        {
            root->left = build(inL, inL + num_left - 1, postL, postL + num_left - 1, in, post);
        }
        if (num_right > 0)
        {
            root->right = build(inR - num_right + 1, inR, postR - num_right, postR - 1, in, post);
        }
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
    }
};
