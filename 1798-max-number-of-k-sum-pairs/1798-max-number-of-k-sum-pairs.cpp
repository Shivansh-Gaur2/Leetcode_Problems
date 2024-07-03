class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        int left = 0, right = nums.size() - 1;

        while(left < right){
            cout << nums[left] << " <-left " << nums[right] << endl;
            if(nums[left] + nums[right] == k){
                left++;
                right--;
                ans++;
            }
            else if(nums[left] + nums[right] < k){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};