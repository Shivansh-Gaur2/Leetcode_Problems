class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end(), 0);

        int left = 0;
        int right;

        for(int i = 0 ; i < nums.size(); i++){
            right = total - left - nums[i];

            if(left == right){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};