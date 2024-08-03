class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int, int>> ump(n);
        for (auto it : pick) {
            ump[it[0]][it[1]]++;
        }

        int winners = 0;
        for (int i = 0; i < n; i++) {
            for (auto& [color, count] : ump[i]) {
                if (count > i) {
                    winners++;
                    break;
                }
            }
        }

        return winners;
    }
};