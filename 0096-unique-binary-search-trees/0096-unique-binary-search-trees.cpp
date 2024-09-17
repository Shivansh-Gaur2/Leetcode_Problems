class Solution {
    private: 
    int subTree(int start, int end){
        if(start > end){
            return 1;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int total = 0;
        for(int i = start; i <= end; i++){
            int leftTree =  subTree(start, i-1);
            int rightTree =  subTree(i+1, end);

            total +=  leftTree * rightTree;
        }

        return dp[start][end] = total;
    }
public:
    vector<vector<int>> dp;

    int numTrees(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return subTree(1, n);
    }
};