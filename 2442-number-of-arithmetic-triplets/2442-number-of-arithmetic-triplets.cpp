class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
        unordered_map<int,int> ump;

        for(int i = 0 ; i < nums.size(); i++){
            ump[nums[i]]++;
        }

        for(int i = 0 ; i < nums.size() ;i++){
            if(ump.find(nums[i] + diff) != ump.end() && ump.find(nums[i] + 2*diff) != ump.end())cnt++;
        }
        return cnt;
    }
};