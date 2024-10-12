class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = findMinimalCandidate(nums[i]);
        }

        return ans;
    }

private:
    int findMinimalCandidate(int num) {
        int minimalAns = INT_MAX;
        bool found = false;

        for (int bit = 0; bit <= 30; bit++) {
            if (isBitSet(num, bit)) {
                int candidate = unsetBit(num, bit);

                if (isValidCandidate(candidate, num)) {
                    if (candidate < minimalAns) {
                        minimalAns = candidate;
                        found = true;
                    }
                }
            }
        }

        return found ? minimalAns : -1;
    }

    bool isBitSet(int num, int bit) {
        return ((num >> bit) & 1) == 1;  
    }

    int unsetBit(int num, int bit) {
        return num & ~(1 << bit);  
    }

    bool isValidCandidate(int candidate, int originalNum) {
        return (candidate | (candidate + 1)) == originalNum;
    }
};