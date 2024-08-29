class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n , 0);
        int maxi = nums[0];
        prefix[0] = nums[0]*2;
        for(int i = 1; i < n; i++){
            maxi = max(nums[i] , maxi);
            prefix[i] = nums[i] + maxi;
            prefix[i] += prefix[i-1];

        }

        return prefix;
    }
};