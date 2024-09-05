class Solution {
public:
    bool helper(vector<int>& ans, int idx, int rem, int n) {
        if (idx == n) {
            return rem == 0;
        }

        int minPossible = (n - idx);
        int maxPossible = (n - idx) * 6;

        if (rem < minPossible || rem > maxPossible) {
            return false;
        }

        for (int i = 1; i <= 6; i++) {
            if (rem - i >= 0) {
                ans[idx] = i;
                if (helper(ans, idx + 1, rem - i, n)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = n + m;

        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }

        int rem = total * mean - sum;
        
        if (rem < n || rem > n * 6) {
            return {};
        }

        vector<int> ans(n, 0);
        if (!helper(ans, 0, rem, n)) {
            return {};
        }

        return ans;
    }
};
