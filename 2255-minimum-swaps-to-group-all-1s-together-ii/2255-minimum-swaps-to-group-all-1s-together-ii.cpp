class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cntOnes = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) cntOnes++;
            nums.push_back(nums[i]);
        }

        int cnt = 0;
        int low = 0, high = 0;
        int minSwaps = INT_MAX;

        while(high < cntOnes) {
            if(nums[high] == 0) {
                cnt++;
            }
            high++;
        }
        minSwaps = min(minSwaps, cnt);

        while(high < nums.size()) {
            if (nums[low] == 0) cnt--;
            if (nums[high] == 0) cnt++;
            minSwaps = min(minSwaps, cnt);
            low++;
            high++;
        }

        return minSwaps;
    }
};
