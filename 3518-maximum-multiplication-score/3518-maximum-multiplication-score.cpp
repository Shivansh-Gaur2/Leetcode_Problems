class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(4, vector<long long>(n, LLONG_MIN)); 

        for (int j = 0; j < n; ++j) {
            dp[0][j] = static_cast<long long>(a[0]) * b[j];
        }

        for (int i = 1; i < 4; ++i) {
            long long max_prev = LLONG_MIN;
            for (int j = i; j < n; ++j) {
                max_prev = max(max_prev, dp[i - 1][j - 1]);
                dp[i][j] = max_prev + static_cast<long long>(a[i]) * b[j];
            }
        }

        long long result = LLONG_MIN;
        for (int j = 3; j < n; ++j) {
            result = max(result, dp[3][j]);
        }

        return result;
    }
};
