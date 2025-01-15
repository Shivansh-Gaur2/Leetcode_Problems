class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int prev = -1, after = -1;

        int left = 0, right = nums.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                int k = mid;
                while(k >= 0 && (nums[k] == target))prev = k, k--;
                k = mid;
                while(k < nums.size() && (nums[k] == target)) after = k, k++;
                break;
            }
            if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return {prev, after};
    }
};