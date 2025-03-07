class Solution {
public:
int f(int prevIdx, int idx, vector<vector<int>>&dp, vector<int>& nums, int n){
    if(idx == n) return nums[prevIdx];
    if(idx == n-1) return max(nums[prevIdx] , nums[idx]);
    if(dp[prevIdx][idx] != -1) return dp[prevIdx][idx];

    int opt1 = max(nums[prevIdx], nums[idx]) + f(idx+1, idx+2, dp, nums, n);
    int opt2 = max(nums[prevIdx], nums[idx+1]) + f(idx, idx+2, dp, nums, n);
    int opt3 = max(nums[idx], nums[idx+1]) + f(prevIdx, idx+2, dp, nums, n);
    
    return dp[prevIdx][idx] = min(opt1, min(opt2, opt3));
}
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(0, 1, dp, nums, n);
    }
};