class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> ump;
        int cnt = 0;
        int maxFreq = 0;
        for(int i = 0 ; i < nums.size(); i++){
            ump[nums[i]]++;
            maxFreq= max(maxFreq, ump[nums[i]]);
        }

        for(auto it : ump){
            if(it.second == maxFreq){
                cnt += it.second;
            }
        }

        return cnt;
    }
};