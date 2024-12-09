class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n , 0);
        vector<bool> ans;

        for(int i = 1 ; i < n; i++){
            if((nums[i] & 1) == (nums[i-1] &1)){
                prefix[i] = prefix[i-1] + 1;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }

        for(auto it : queries){
            int startIndex = it[0];
            int endIndex = it[1];

            if(prefix[endIndex] - prefix[startIndex] == 0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};