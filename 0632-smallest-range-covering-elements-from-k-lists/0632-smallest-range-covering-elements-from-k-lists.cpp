class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int curr = INT_MIN;

        for(int i = 0 ; i < nums.size(); i++){
            pq.push({nums[i][0], i, 0});
            curr = max(curr, nums[i][0]);
        }

        vector<int> ans = {pq.top()[0], curr};

        while(!pq.empty()){
            auto sm = pq.top();
            pq.pop();

            int val = sm[0], row = sm[1], idx = sm[2];

            if(curr - val < ans[1] - ans[0]){
                ans = {val, curr};
            }

            if(idx+1 < nums[row].size()){
                pq.push({nums[row][idx+1], row, idx+1});
                curr = max(curr, nums[row][idx+1]);
            }
            else{
                break;
            }
        }

        return ans;
    }

};