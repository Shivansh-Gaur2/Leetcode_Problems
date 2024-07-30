class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double mini = INT_MAX;

        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            mini = min(mini, (double)(nums[low]+nums[high])/2);
            low++;
            high--;
        }
        return mini;
    }
};