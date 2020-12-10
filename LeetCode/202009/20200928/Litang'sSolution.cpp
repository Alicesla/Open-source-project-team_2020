/*
   Author: litang
   Description: 
   Since: 2020/09/28
          08:36:17
*/
#include "head.h"

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
    int cnt = 1, nextCnt = 0;

public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            for (int i = 0; i < cnt; ++i)
            {
                auto f = q.front();
                q.pop();
                f->next = i == cnt - 1 ? nullptr : q.front();
                if (f->left)
                {
                    q.push(f->left);
                    nextCnt++;
                }
                if (f->right)
                {
                    q.push(f->right);
                    nextCnt++;
                }
            }
            cnt = nextCnt;
            nextCnt = 0;
        }
        return root;
    }
};
//法2
class Solution
{
    //可以将空间复杂度优化到O(1)
    //前序遍历的思想
    //DRL,否则父节点的next可能来不及初始化
    //左孩子的next是右孩子, 根节点next的左孩子, 根节点next的右孩子中存在的一个, 否则为nullptr
    //右孩子的next是父节点next的左孩子, 父节点next的右孩子中存在的一个,否则为nullptr
    //根节点的next为nullptr
public:
    void DRL(Node *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            if (root->right)
                root->left->next = root->right;
            else if (root->next)
            {
                auto p = root->next;
                while (p)
                {
                    if (p->left)
                    {
                        root->left->next = p->left;
                        break;
                    }
                    else if (p->right)
                    {
                        root->left->next = p->right;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        if (root->right)
        {
            if (root->next)
            {
                auto p = root->next;
                while (p)
                {
                    if (p->left)
                    {
                        root->right->next = p->left;
                        break;
                    }
                    else if (p->right)
                    {
                        root->right->next = p->right;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        DRL(root->right);
        DRL(root->left);
    }
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        root->next = nullptr;
        DRL(root);
        return root;
    }
};
