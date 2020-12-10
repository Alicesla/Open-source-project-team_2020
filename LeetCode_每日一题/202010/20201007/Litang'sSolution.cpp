class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if( nums.size() < 3) 
        {sort(nums.begin(), nums.end());return;}
        const int si = nums.size();
        int i = 0, j = si - 1;
        while (nums[i] == 0)
            ++i;
        while (nums[j] == 2)
            --j;
        for (int k = i; k<=j; k = k + 1> i ? k + 1 : i)
        {
            if( nums[k] == 2)
            {
                swap(nums[j], nums[k]);
                while( nums[j] == 2)
                    --j;
            }
            if (!nums[k])
            {
                swap(nums[i], nums[k]);
                while (!nums[i])
                    ++i;
            }
        }
    }
};
