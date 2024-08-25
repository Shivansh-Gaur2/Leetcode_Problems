class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int minIndex = distance(nums.begin(), min_element(nums.begin(), nums.end()));
            nums[minIndex] = nums[minIndex] * multiplier;
        }

        return nums;
    }
};