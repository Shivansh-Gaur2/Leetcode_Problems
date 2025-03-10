class Solution {
public:
    long long f(string s, int k) {
        unordered_map<char, int> ump;
        long long ans = 0, l = 0, c = 0;
        for (int r = 0; r < s.size(); r++) {
            isVowel(s[r]) ? ump[s[r]]++ : c++;

            while (ump.size() == 5 && c >= k) {
                ans += s.size() - r;
                if(isVowel(s[l])) {
                    if (--ump[s[l]] == 0)
                        ump.erase(s[l]);
                } else {
                    c--;
                }
                l++;
            }
        }
        return ans;
    }
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k + 1);
    }
};