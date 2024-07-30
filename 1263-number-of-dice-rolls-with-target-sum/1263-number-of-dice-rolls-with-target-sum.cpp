class Solution {
private:
    int helper(int n,int k,int t,vector<vector<int>>& memo){
        if(n>t || t>n*k) return 0;
        if(n==0 && t!=0) return memo[n][t]=0;
        if(n==0 && t==0) return memo[n][t]=1;
        if(memo[n][t]!=-1) return memo[n][t];
        int cnt=0;
        for(int i=1;i<=k;i++){
            cnt=(cnt+helper(n-1,k,t-i,memo))%1000000007;
        }
        return memo[n][t]=cnt;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n+1,vector<int>(target+1,-1));
        return helper(n,k,target,memo);
    }
};