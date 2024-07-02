class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        s = "";
        string word;
        while(ss >> word){
            cout << word << endl;
            s = word + ' ' + s;
        }

        return s.substr(0, s.size() - 1);
    }
};