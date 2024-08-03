class Solution {
public:
bool helper(vector<int>& nums ,int idx, int target, vector<vector<int>>& dp){
    if(target == 0) return true;
    if(target < 0) return false;
    if(idx >= nums.size()) return false;
    if(dp[idx][target] != -1){
        return dp[idx][target];
    }

    bool inc = helper(nums , idx + 1, target - nums[idx], dp);
    bool exl = helper(nums, idx + 1, target, dp);

    return  dp[idx][target] = inc || exl;
}


    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        if(total% 2 != 0){
            return 0;
        }
        vector<vector<int>> dp(nums.size()+1 , vector<int>(total/2 + 1 , -1));
        return helper(nums,  0,  total/2, dp);
    }
};