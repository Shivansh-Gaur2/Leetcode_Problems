class Solution {
public:
const int mod = 1e9 + 7;
const int N =1e5+1;


    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(N, 0);

        memo[0] = 1;

        for(int i = 1; i <= high; i++){
            if(i >= zero) memo[i] = (memo[i] + memo[i-zero]) % mod;
            if(i >= one) memo[i] = (memo[i] + memo[i-one]) % mod; 
        }

        int ans = 0;
        for(int i = low ; i <= high; i++){
            ans = (ans + memo[i]) % mod;
        }

        return ans;
    }
};