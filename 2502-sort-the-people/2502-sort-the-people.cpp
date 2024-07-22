class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> ump;
        
        for(int i = 0; i < names.size(); i++){
            ump[heights[i]] = names[i];
        }
        
        sort(heights.begin(), heights.end(), greater<int>());
        
        for(int i = 0; i < heights.size(); i++){
            names[i] = ump[heights[i]];
        }
        
        return names;
    }
};