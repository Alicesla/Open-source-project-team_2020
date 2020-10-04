class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
       for( int i = 0; i < nums.size(); ++i)
       {
           auto it = mp.find(target - nums[i]);
           if( it != mp.end() ) return {it->second, i};
           mp[nums[i]] = i;
       }
        return {};
    }
};
