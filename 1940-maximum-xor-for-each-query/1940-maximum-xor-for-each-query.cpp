class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxBits) {
        int maxVal = (1 << maxBits) - 1;
        int n = nums.size();
        vector<int> prefixXor(n);
        prefixXor[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ nums[i];
        }

        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            result[i] = prefixXor[i] ^ maxVal;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
