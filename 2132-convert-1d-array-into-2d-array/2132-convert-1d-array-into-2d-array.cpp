class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()){
            return {};
        }
        vector<vector<int>> ans;
        int index = 0;
        for(int i = 0 ; i < m; i++){
            vector<int> temp(n , 0);
            for(int j = 0 ; j < n ; j++){
                temp[j] = original[index];
                index++;
            }
            ans.push_back(temp);
        }
    return ans;
    }
};