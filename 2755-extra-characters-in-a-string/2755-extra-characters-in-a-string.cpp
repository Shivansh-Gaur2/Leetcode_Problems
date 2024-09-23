class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        int n = s.size();

        vector<int> dp(n + 1, n + 1);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

            for (int len = 1; len <= n - i; len++) {
                string st = s.substr(i, len);
                if (dict.find(st) != dict.end()) {
                    dp[i + len] = min(dp[i + len], dp[i]);
                }
            }
        }
        return dp[n];
    }
};