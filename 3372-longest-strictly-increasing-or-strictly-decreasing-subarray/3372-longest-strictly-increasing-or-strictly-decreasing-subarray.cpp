class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1; 
        int n = nums.size();

        int left = 0;
        for (int right = 1; right < n; right++) {
            if (nums[right] > nums[right - 1]) continue;
            ans = max(ans, right - left);
            left = right;
        }
        ans = max(ans, n - left); 

        int right = n - 1;
        for (int left = n - 2; left >= 0; left--) {
            if (nums[left] > nums[left + 1]) continue;
            ans = max(ans, right - left);
            right = left;
        }
        ans = max(ans, right + 1); 

        return ans;
    }
};
