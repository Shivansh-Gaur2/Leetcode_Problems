class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len == 0){
            return s;
        }
        int left = 0;
        for(int right = len- 1; right >= 0 ; right--){
            if(s[right] == s[left]){
                left++;
            }
        }
        if(left == len){
            return s;
        }

        string nonPalindrome = s.substr(left);
        string reverseSuffix = string(nonPalindrome.rbegin(), nonPalindrome.rend());

        return reverseSuffix + shortestPalindrome(s.substr(0, left)) + nonPalindrome;
    }
};