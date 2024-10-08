class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minElem = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums) {
            ans += num - minElem;
        }
        return ans;
    }
};
