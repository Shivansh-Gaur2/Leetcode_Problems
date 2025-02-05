class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0;
        int currSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                currSum += nums[i];
            }
            else{
                maxi = max(maxi, currSum);
                currSum = nums[i];
            }
        }
        return max(maxi, currSum);
    }
};