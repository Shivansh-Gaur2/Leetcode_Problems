class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int cntZ = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                cntZ++;
            }

            if (cntZ > 1) {
                if (nums[left] == 0) {
                    cntZ--;
                }
                left++;
            }

            ans = max(ans, right - left); 
        }

        return ans;
    }
};
