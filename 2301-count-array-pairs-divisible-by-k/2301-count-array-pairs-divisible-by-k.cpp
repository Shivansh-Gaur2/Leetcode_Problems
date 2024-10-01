class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> ump;

        for (long long i = 0; i < nums.size(); i++) {
            long long gcd1 = gcd(nums[i], k);

            for (auto& it : ump) {
                long long gcd2 = it.first;
                if ((gcd1 * gcd2) % k == 0) {
                    ans += it.second;
                }
            }

            ump[gcd1]++;
        }
        
        return ans;
    }
};
