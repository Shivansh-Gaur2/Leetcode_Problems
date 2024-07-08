class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for(int i = 2; i <= n; i++){
            cout << ans << " " << k <<" "<< (ans + k) << " "<< (ans+k)%i << endl;
            ans = (ans + k) % i;
            // cout << ans << endl;
        }
        return ans + 1;
    }
};