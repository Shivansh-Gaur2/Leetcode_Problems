class Solution {
public:
int helper(int idx, vector<int>& prices, bool buy, vector<vector<int>> &dp){
    if(idx >= prices.size()){
        return 0;
    }
    if(dp[idx][buy] != -1){
        return dp[idx][buy];
    }
    if(buy){
        dp[idx][buy] = max(-prices[idx] + helper(idx + 1, prices, false, dp), helper(idx + 1, prices, true, dp));
    }
    else{
        dp[idx][buy] = max(+prices[idx] + helper(idx + 2, prices, true, dp), 0 + helper(idx + 1, prices, false, dp));
    }

    return dp[idx][buy];
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size() + 2 , vector<int>(2, -1));
        return helper(0, prices, true, dp);        
    }
};