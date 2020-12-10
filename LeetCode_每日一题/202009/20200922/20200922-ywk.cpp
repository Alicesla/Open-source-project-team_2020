/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct status{
    int counter;
    int type;
};

class Solution {
public:
    status DFS(TreeNode* root) {
        if (root == NULL)
        {
            return {0,1};//important
        }
   
        status leftSituation = DFS(root->left);
        status rightSituation = DFS(root->right);

        if (leftSituation.type == 1 && rightSituation.type == 1)
        {
            return {leftSituation.counter+rightSituation.counter,0};
        }
        if (leftSituation.type == 0 || rightSituation.type == 0)
        {
            return {leftSituation.counter+rightSituation.counter+1,2};
        }
        if (leftSituation.type + rightSituation.type > 2)
        {
            return {leftSituation.counter+rightSituation.counter,1};
        }
        return {0,1};
    }
    int minCameraCover(TreeNode *root)
    {
        status ans = DFS(root);
        if (ans.type == 0)
        {
            return ans.counter+1;
        }
        return ans.counter;
        
    }
};