class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        long long ans = 0;
        
        while(left <= right){

            ans += nums[left];
            left++;
        }
        

        return ans;
    }
};