class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curr, int i) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            
            if (candidates[j] > target) break; 
            
            curr.push_back(candidates[j]);
            helper(candidates, target - candidates[j], ans, curr, j + 1); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ans, curr, 0);
        return ans;
    }
};
