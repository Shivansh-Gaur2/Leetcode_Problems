class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], (i + 2 <= n ? dp[i + 2] : 0));
        }

        return min(dp[0], dp[1]);
    }
};
