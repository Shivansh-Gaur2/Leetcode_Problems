class Solution {
public:
    void helper(vector<int>& nums, int idx, int maxi, int& cnt, int curr) {
        if (idx == nums.size()) {
            if (curr == maxi) {
                cnt++;
            }
            return;
        }
        helper(nums, idx + 1, maxi, cnt, curr);
        helper(nums, idx + 1, maxi, cnt, curr | nums[idx]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxi |= nums[i];
        }
        helper(nums, 0, maxi, cnt, 0);
        return cnt;
    }
};
