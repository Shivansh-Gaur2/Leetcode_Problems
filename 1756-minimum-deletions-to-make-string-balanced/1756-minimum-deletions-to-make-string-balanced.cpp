class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> countA(n , 0);
        vector<int> countB(n , 0);

        int b_cnt = 0;

        for(int i = 0 ; i < n; i++){
            countB[i] = b_cnt;
            if(s[i] == 'b'){
                b_cnt++;
            }
        }

        int a_cnt = 0;
        for(int i = n-1 ; i >= 0; i--){
            countA[i] = a_cnt;
            if(s[i] == 'a') a_cnt++;
        }

        int mini = n;
        for(int i = 0; i < n ; i++){
            mini = min(mini, countA[i] + countB[i]);
        }

        return mini;
    }

};