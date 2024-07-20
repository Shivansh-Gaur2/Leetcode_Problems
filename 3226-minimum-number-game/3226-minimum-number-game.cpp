class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int ali = 0;
        int bob = 1;
        while(bob < nums.size()){
            ans.push_back(nums[bob]);
            ans.push_back(nums[ali]);
            bob+= 2;
            ali+= 2;
        }
        return ans;
    }
};