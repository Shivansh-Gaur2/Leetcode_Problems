class Solution {
public:
    int dp[101][101];
    int solve(int m,int n){
        if(m==1 || n==1){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        return dp[m][n]=solve(m-1,n)+solve(m,n-1);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n);
    }
};