class Solution {
public:
    void dfs1(int cur,int father)
    {
        nums[cur]=1;dp[cur]=0;
        for (auto v:p[cur])
        {
            if (v==father) continue;
            dfs1(v,cur);
            dp[cur]+=dp[v]+nums[v];
            nums[cur]+=nums[v];
        }
    }
    void dfs2(int cur,int father)
    {
        for (auto v:p[cur])
        {
            if (v==father) continue;
            dp[v]=dp[cur]+n-2*nums[v];
            dfs2(v,cur);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n=N;
        nums.resize(n,0);
        dp.resize(n,0);
        p.resize(n,vector<int>());
        for (auto edge:edges)
        {
            int i=edge[0],j=edge[1];
            p[i].push_back(j);
            p[j].push_back(i);
        }

        dfs1(0,-1);
        dfs2(0,-1);
        return dp;
    }
private:
    int n=0;
    vector<int> nums,dp;
    vector<vector<int>> p;
};
