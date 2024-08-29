class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n , 0);
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(nums[i] , maxi);
            prefix[i] = nums[i] + maxi;
        }
         
        for(int i = 1 ; i < n ;i++){
            prefix[i] += prefix[i-1];
        }

        return prefix;
    }
};