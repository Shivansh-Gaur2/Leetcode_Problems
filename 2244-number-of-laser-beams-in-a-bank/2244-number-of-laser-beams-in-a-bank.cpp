class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ans;
        int tot = 0;
        for(int i = 0 ; i < bank.size(); i++){
        int cnt = 0;
            for(auto it : bank[i]){
                if(it == '1'){
                    cnt++;
                }

            }
            if(cnt > 0){
                ans.push_back(cnt);
            }
        }

        for(int i =1; i < ans.size(); i++){
            tot += ans[i] * ans[i-1];
        }
        return tot;
    }
};