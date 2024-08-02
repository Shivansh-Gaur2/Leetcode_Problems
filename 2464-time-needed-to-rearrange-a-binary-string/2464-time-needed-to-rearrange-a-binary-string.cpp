class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int time = 0;
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i-1] == '0' && s[i] == '1') {
                    swap(s[i-1], s[i]);
                    ++i; 
                    changed = true;
                }
            }
            if (changed) {
                ++time;
            }
        }

        return time;
    }
};
