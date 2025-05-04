class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int l = 0, r= s.size()-1;
        if(s[0] == '-'){
            l = 1;
        }
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
        try {
            return stoi(s);
        } catch (const out_of_range&) {
            return 0;
        }
    }
};