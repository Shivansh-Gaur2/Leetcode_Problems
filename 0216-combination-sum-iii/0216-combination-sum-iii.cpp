class Solution {
public:
    void helper(int i, int k, int n, vector<int>& temp, vector<vector<int>>& ans) {
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }
        if (i > 9 || n < 0 || k < 0) {
            return;
        }

        temp.push_back(i);
        helper(i + 1, k - 1, n - i, temp, ans);  
        temp.pop_back();
        helper(i + 1, k, n, temp, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1, k, n, temp, ans);
        return ans;
    }
};
