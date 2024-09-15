class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0;
        int left = 0;
        int maxNum = nums[0];
        for(int right = 0 ; right < nums.size(); right++){
            if(nums[left] == nums[right] && maxNum == nums[left]){
                len = max(len, right - left + 1);
            }
            else{
                left = right;
            }
            if(nums[right] > maxNum){
                len = 1;
                maxNum = nums[right];
            }
        }
        return len;
    }
};