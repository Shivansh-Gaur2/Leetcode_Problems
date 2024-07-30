class Solution {
public:
int helper(vector<int>&satisfaction, int index, int time, vector<vector<int>>& dp){
    if(index == satisfaction.size()){
        return 0;
    }

    if(dp[index][time] != -1){
        return dp[index][time];
    }

    int include = satisfaction[index]*(time+1) + helper(satisfaction, index+1, time+1, dp);
    int exclude = helper(satisfaction, index+1, time, dp);

    return dp[index][time] =  max(include, exclude);
}
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        vector<vector<int>>dp(n+1 , vector<int>(n+1, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return helper(satisfaction, 0, 0, dp);
    }
};