class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int sum = 0;
        double maxi = INT_MIN;
        while(right < nums.size()){
            sum += nums[right];
            if(right - left+1 == k){
                maxi = max(maxi, (double)sum / k);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return maxi;
    }
};