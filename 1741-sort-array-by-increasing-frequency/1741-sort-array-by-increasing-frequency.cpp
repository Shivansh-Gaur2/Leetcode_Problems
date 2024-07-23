class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int ,int> ump;

        for(int i = 0 ; i < nums.size(); i++){
            ump[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(ump[a] == ump[b]){
                return a > b;
            }
            return ump[a] < ump[b];
        });

        return nums;
    }
};