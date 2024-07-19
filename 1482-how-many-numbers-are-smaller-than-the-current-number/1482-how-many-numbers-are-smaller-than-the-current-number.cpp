class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> ump;
        vector<int> arr;

        arr = nums;
        sort(arr.begin(), arr.end());

        for(int i = nums.size() - 1; i >= 0; i--){
            ump[arr[i]] = i;
        }
        for(int i =0 ; i < nums.size();i++){
            nums[i] = ump[nums[i]];
        }
        return nums;
    }
};