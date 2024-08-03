class Solution {
public:
vector<char> vow = {'a', 'e', 'i', 'o' , 'u'};
int helper(int index, int n, vector<vector<int>>&dp){
    if(n == 0){
        return 1;
    }
    if(dp[index][n] != -1){
        return dp[index][n];
    }
    int cnt = 0; 
    for(int i = index; i < vow.size(); i++){
        cnt += helper(i , n-1, dp);
    }
    return dp[index][n] = cnt;
}
    int countVowelStrings(int n) {
        vector<vector<int>>dp(vow.size(), vector<int>(n+1, -1));
        return helper(0, n ,dp);
    }
};