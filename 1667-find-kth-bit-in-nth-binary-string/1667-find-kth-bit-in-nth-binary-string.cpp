class Solution {
public:
void helper(string& s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = (s[i] == '0') ? '1' : '0';  
    }
    // cout << s << endl;
}

    char findKthBit(int n, int k) {
        string s = "0";
        while(n != 1){
            string s1 = s;
            helper(s1);
            reverse(s1.begin(), s1.end());
            s = s + "1" + s1;
            n--;
        }
        cout << s << endl;
        return s[k-1];
    }
};