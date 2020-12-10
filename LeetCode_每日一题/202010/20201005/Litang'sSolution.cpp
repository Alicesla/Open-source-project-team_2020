class Solution
{
    vector<vector<int>> ans;
    vector<int> temp;
    int cnt = 0;

public:
    void backTrace(vector<int> &nums, int pre, int sum, const int &target)
    {
       
        if (4 - temp.size() > nums.size() - 1 - pre)
            return;
         if (pre + 1 < nums.size() && (sum + int(4 - temp.size()) * nums[ pre + 1] > target))
            return;
        if (temp.size() == 4)
        {
            if (sum == target)
                ans.push_back(temp);
            return;
        }
        for (int i = pre + 1; i < nums.size(); ++i)
        {
            if ((i != pre + 1) && (nums[i] == nums[i - 1]))
                continue;
            if (sum + nums[i] + int(3 - temp.size()) * nums[nums.size() - 1] < target)
                continue;
            temp.push_back(nums[i]);
            backTrace(nums, i, sum + nums[i], target);
            temp.pop_back();
        }
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        if (nums.empty())
            return ans;
        backTrace(nums, -1, 0, target);
        return ans;
    }
};
