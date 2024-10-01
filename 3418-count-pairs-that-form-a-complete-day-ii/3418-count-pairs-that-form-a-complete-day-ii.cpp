class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long cnt = 0;
        unordered_map<int, int> ump;
        
        for (int i = 0; i < hours.size(); i++) {
            if (ump.find((24 - (hours[i] % 24)) % 24) != ump.end()) {
                cnt += ump[(24 - (hours[i] % 24)) % 24];
            }
            ump[hours[i] % 24]++;
        }

        return cnt;
    }
};
