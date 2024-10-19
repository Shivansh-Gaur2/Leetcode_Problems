bool palindrome(string &s,int i,int j){
    while(i<j){
        if (s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int helper(string &s,int i,vector <int> &dp){
    if (i==s.length()){
        return 0;
    }
    if (dp[i]!=-1){
        return dp[i];
    }
    int mini=INT_MAX;
    for(int k=i;k<s.length();k++){
        if (palindrome(s,i,k)){
            int cost=helper(s,k+1,dp);
            if (k!=s.length()-1){
                cost++;
            }
            mini=min(mini,cost);
        }
    }
    dp[i]=mini;
    return dp[i];
}
class Solution {
public:
    int minCut(string s) {
        vector <int> dp(s.length(),-1);
        return helper(s,0,dp);
    }
};