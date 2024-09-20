class Solution {
public:
int helper(int n, vector<int>&dp){
    if(n == 2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int maxProd = INT_MIN;
    for(int i = 1; i < n ; i++){
        maxProd = max(maxProd,i* max(n-i, helper(n-i, dp)));
    }

    return dp[n] = maxProd;

}
    int integerBreak(int n) {
        vector<int>dp(n+1, -1);
        return helper(n, dp);
    }
};