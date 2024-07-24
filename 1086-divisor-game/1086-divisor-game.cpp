class Solution {
public:
bool helper(int num, vector<int>&dp){
    if(num == 1){
        return false;
    }
    if(dp[num] != -1){
        return dp[num];
    }
    bool ans = false;
    for(int i= 1; i*i < num; i++){
        if(num%i == 0){
            if(!helper(num-i,dp)){
                ans = true;
                break;
            }
        }
    }
    return dp[num] = ans;
}
    bool divisorGame(int n) {
        vector<int>dp(n+1, -1);
       return helper(n, dp);
    }
};