class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> ump;
        for(int i = 0 ; i < nums.size(); i++){
            if(ump.find(nums[i]) == ump.end()){
                ump[nums[i]]++;
            }
            else{
                cnt += ump[nums[i]];
                ump[nums[i]]++;
            }
        }
        return cnt;
    }
};