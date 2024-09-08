class Solution {
public:
    long long calculateScore(const vector<int>& nums, int startIdx, int endIdx, int value) {
        return value * 1LL * (endIdx - startIdx);
    }

    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long totalScore = 0;
        int previousIndex = 0;
        int currentValue = nums[0];
    
        for (int i = 1; i < n; ++i) {
            if (nums[i] > currentValue) {
                totalScore += calculateScore(nums, previousIndex, i, currentValue);
                currentValue = nums[i];
                previousIndex = i;
            }
        }
        
        totalScore += calculateScore(nums, previousIndex, n - 1, currentValue);
        return totalScore;
    }
};
