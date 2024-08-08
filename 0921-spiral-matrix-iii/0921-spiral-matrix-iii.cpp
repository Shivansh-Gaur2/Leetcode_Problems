class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int cnt = rows * cols;
        
        int direction = 0; 
        int steps = 1;     
        
        while (cnt > 0) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < steps; ++j) {
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                        cnt--;
                    }
                    if (direction == 0) cStart++; 
                    else if (direction == 1) rStart++;
                    else if (direction == 2) cStart--;
                    else if (direction == 3) rStart--;
                }
                direction = (direction + 1) % 4;
            }
            steps++;
        }
        
        return ans;
    }
};
