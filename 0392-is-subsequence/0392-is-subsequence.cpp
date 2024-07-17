class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a = 0, b = 0;
        int cnt = 0;
        while(b < t.size()){
            if(t[b] == s[a]){
                cnt++;
                a++;
            }
            b++;
        }
        return cnt == s.size();
    }
};