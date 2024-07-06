class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int i = 0, j = 0, ans = 0;
        long long sum = 0;
        int n = nums.size();
        for (j = 0; j < n; j++) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i++];
            }
            ans += j - i + 1;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};