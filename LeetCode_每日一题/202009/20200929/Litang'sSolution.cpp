class Solution
{
    //需要一个辅助栈
    //左子树&&右子树非空时连续压入左子树;出栈时输出数字,同时将父节点(即st.top())的右子树压栈
    //一开始将root压栈
    stack<TreeNode *> st;
    vector<int> res;
    bool flag = true;
    TreeNode *pre = nullptr;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return res;
        st.push(root);
        while (!st.empty())
        {
            if (flag)
            {
                while (st.top()->left)
                {
                    pre = st.top();
                    st.push(st.top()->left);
                }
                auto t = st.top();
                flag = false;
                if (t->right)
                {
                    pre = t;
                    st.push(t->right);
                    flag = true;
                    continue;
                }
            }

            auto t = st.top();
            st.pop();
            res.push_back(t->val);

            if (pre && t==pre->left && !st.empty() && st.top()->right)
            {
                pre = st.top();
                st.push(st.top()->right);
                flag = true;
            }
        }
        return res;
    }
};
