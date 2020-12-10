/*
   Author: litang
   Description: 
   Since: 2020/09/26
          09:05:38
*/
class Solution
{
    vector<vector<int>> res;
    vector<int> temp;
public:
    void backTrace(TreeNode *root, int sum)
    {
        if (!root)
            return;
        sum -= root->val;
        temp.push_back(root->val);
        if (!sum && !root->left && !root->right)
        {
            res.push_back(temp);
            temp.pop_back();
            return;
        }
            backTrace(root->left, sum);
            backTrace(root->right, sum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        backTrace(root, sum);
        return res;
    }
};
