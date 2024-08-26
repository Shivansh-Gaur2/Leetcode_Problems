class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int start =  nums[0][0];
        int end = nums[0][1];

        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i][0] <= end){
                end = max(nums[i][1], end);
            }
            else{
                ans += end - start +1;
                start = nums[i][0];
                end = nums[i][1];
            }
        }

        ans += end - start + 1;
        return ans;
    }
};