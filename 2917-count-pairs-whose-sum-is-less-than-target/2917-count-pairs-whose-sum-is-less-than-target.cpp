class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left= 0;
        int right = nums.size() -1;
        int cnt = 0;
        while(left < right){
            if(nums[left] + nums[right] < target){
                cnt+= right - left;
                left++;
            }
            else{
                right--;
            }
        }
        return cnt;
    }
};