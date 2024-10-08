class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for (int i = 0; i < s.size(); i++) {
            num += to_string(s[i] - 'a' + 1); 
        }

        while (k--) {
            long long int ans = 0;
            for (char c : num) {
                ans += c - '0'; 
            }
            num = to_string(ans); 
        }
        
        return stoi(num);
    }
};
