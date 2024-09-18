class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string s = "";

        vector<string> ans(n, "");
        for(int i = 0 ; i < ans.size(); i++){
            ans[i] = to_string(nums[i]);
        }
        sort(ans.begin(), ans.end(), [](string &a, string &b){
            return a + b > b + a;
        });

        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
            s += ans[i];
        }

        bool allZero = true;
        for(auto it : s){
            if(it != '0'){
                allZero = false;
                break;
            }
        }
        return allZero ? "0" : s;
    }
};