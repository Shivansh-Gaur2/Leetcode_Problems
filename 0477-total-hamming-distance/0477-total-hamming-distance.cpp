class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int ones = 0;
            for(auto num : nums){
                if((num & (1 << i))) ones++;
            }
            ans += ones * (n - ones);
        }
        return ans;
    }
};