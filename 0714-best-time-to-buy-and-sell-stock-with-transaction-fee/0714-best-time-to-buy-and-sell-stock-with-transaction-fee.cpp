class Solution {
public:
int helper(int idx, int buy, vector<int>& prices, int fee, vector<vector<int>>&dp){
    if(idx == prices.size()){
        return 0;
    }
    if(dp[idx][buy] != -1){
        return dp[idx][buy];
    }

    int profit = 0;
    if(buy){
        int buyKaro = -prices[idx] - fee + helper(idx + 1, 0, prices, fee, dp);
        int skipKaro = helper(idx + 1, 1, prices, fee, dp);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = prices[idx] + helper(idx+1, 1, prices, fee, dp);
        int skipKaro = helper(idx + 1, 0, prices, fee, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[idx][buy] = profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        int  n = prices.size();

        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return helper(0, 1, prices, fee, dp);
    }
};