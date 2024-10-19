class Solution {
public:
    int longestHelper(int i , int j , string &text1, string &text2, vector<vector<int>> &dp){
        if(i <  0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + longestHelper(i-1, j-1, text1, text2, dp);
        }
        else{
            return dp[i][j] = 0 + max(longestHelper(i-1, j ,text1,text2,dp), longestHelper(i, j - 1 , text1, text2,dp));
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size() - 1;
        int j = text2.size() - 1;
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return longestHelper(i, j, text1, text2,dp);
    }
};