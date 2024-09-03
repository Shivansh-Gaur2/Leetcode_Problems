class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        unordered_map<int, int> ump;
        int len = 0;
        int sum = 0;

        ump[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (ump.find(sum) != ump.end()) {
                len = max(len, i - ump[sum]);
            } else {
                ump[sum] = i;
            }
        }

        return len;
    }
};
