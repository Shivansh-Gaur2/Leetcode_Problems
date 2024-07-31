class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi = INT_MIN;

        sort(nums.begin() ,nums.end());
        int low  = 0, high = nums.size()-1;
        while(low < high){
            maxi = max(maxi , (nums[low] + nums[high]));
            low++;
            high--;
        }
        return maxi;
    }
};