class Solution {
public:
    int minimumPushes(string word) {
        vector<int> list(26, 0);

        for(int i = 0 ; i < word.size(); i++){
            list[word[i] - 'a']++;
        }
        sort(list.begin(), list.end());
        reverse(list.begin(), list.end());

        int total = 0;
        for(int i = 0 ; i < list.size(); i++){
            if(list[i] == 0) break;
            total += (i/8 + 1)* list[i];
        }
        return total;
    }
};