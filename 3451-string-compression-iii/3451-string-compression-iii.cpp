class Solution {
public:
    string compressedString(string word) {
        unordered_map<char, int> ump;
        string comp = "";
        char ch = word[0];

        for (int i = 0; i < word.size(); i++) {
            if (ch == word[i]) {
                if (ump[ch] == 9) {
                    comp += to_string(ump[ch]);
                    comp += ch;
                    ump[ch] = 0;
                }
                ump[ch]++;
            } else {
                comp += to_string(ump[ch]);
                comp += ch;
                ump[ch] = 0;
                ch = word[i];
                ump[ch]++;
            }
        }

        comp += to_string(ump[ch]);
        comp += word[word.size() - 1];

        return comp;
    }
};