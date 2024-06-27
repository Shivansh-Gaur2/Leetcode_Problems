class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxi = 0, left = 0 ,right = 1;
        sort(nums.begin(), nums.end());

        while(right < nums.size()){
            if(nums[right] - nums[left] == 1){
                maxi = max(maxi, right - left + 1);
            }
            while(nums[right] - nums[left] > 1){
                left++;
            }
            right++;
        }

        return maxi;
    }
};