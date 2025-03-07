class Solution {
public:
    static const int NEG_INF = -1000000000;
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int dp[2003][2003][2];
        for (int r = 0; r <= k; r++) {
            dp[n][r][0] = (r == 0 ? 0 : NEG_INF);
            dp[n][r][1] = (r == 0 ? 0 : NEG_INF);
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int remaining = 0; remaining <= k; remaining++) {
                if (remaining == 0) {
                    dp[index][0][0] = 0;
                    dp[index][0][1] = max(nums[index] + dp[index + 1][remaining][1], dp[index][remaining][0]);
                } else {
                    int opt2 = NEG_INF;
                    if (m <= n - index)
                        opt2 = (prefix[index + m] - prefix[index]) + dp[index + m][remaining - 1][1];
                    dp[index][remaining][0] = max(dp[index + 1][remaining][0], opt2);
                    dp[index][remaining][1] = max(nums[index] + dp[index + 1][remaining][1], dp[index][remaining][0]);
                }
            }
        }

        return dp[0][k][0];
    }
};