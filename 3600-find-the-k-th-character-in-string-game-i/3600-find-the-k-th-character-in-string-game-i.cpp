class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() <= k){
            int len = word.size();
            for(int i = 0; i < len; i++){
                word += (word[i] - 'a' + 1) + 'a';
            }
        }
        // cout << word << endl;
        return word[k-1];
    }
};