class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int target1 = tops[0];
        int target2 = bottoms[0];
        auto check = [&](int x, vector<int>& A, vector<int>& B) {
            int flipsA = 0, flipsB = 0;
            int n = A.size();
            for (int i = 0; i < n; ++i) {
                if (A[i] != x && B[i] != x) 
                    return INT_MAX;     
                if (A[i] != x) ++flipsA;
                if (B[i] != x) ++flipsB;
            }
            return min(flipsA, flipsB);
        };
        
        int res1 = check(target1, tops, bottoms);
        int res2 = check(target2, tops, bottoms);
        int ans  = min(res1, res2);
        return ans == INT_MAX ? -1 : ans;
    }
};
