class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxLen = 0;
        
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
};
