class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n, INT_MAX);
        if(n == 1){
            return true;
        }
        if(n == 0){
            return false;
        }

        int t2 = 0, t3= 0, t5 = 0;
        ans[0] = 1;
        for(int i = 1 ; i < n; i++){
            ans[i] = min(ans[t2]*2, min(ans[t3]*3, ans[t5]*5));
            if(ans[i] == ans[t2]*2) t2++;
            if(ans[i] == ans[t3]*3) t3++;
            if(ans[i] == ans[t5]*5) t5++;
        }

        return ans[n-1];
    }
};