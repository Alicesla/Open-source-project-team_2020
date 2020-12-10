class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto i = l1, j = l2, shorter = l1, longer = l2, res = l2;
        for (; i != nullptr && j != nullptr; i = i->next, j = j->next)
            ;
        if (i)
        {
            swap(shorter, longer);
            res = l1;
        }
        int flag = 0;
        ListNode *tail = nullptr;
        for (; longer != nullptr; longer = longer->next)
        {
            longer->val += flag;
            if (shorter)
            {
                longer->val += shorter->val;
                shorter = shorter->next;
            }
            if (longer->val >= 10)
            {
                longer->val %= 10;
                flag = 1;
            }
            else
                flag = 0;
            if (!longer->next)
                tail = longer;
        }
        if (flag)
            tail->next = new ListNode(1);
        return res;
    }
};
