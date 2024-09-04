class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> timeline;
        
        for (const auto& trip : trips) {
            timeline[trip[1]] += trip[0]; 
            timeline[trip[2]] -= trip[0];  
        }
        
        int pass = 0;

        for (const auto& entry : timeline) {
            pass += entry.second;
            if (pass > capacity) {
                return false;
            }
        }
        
        return true;
    }
};
