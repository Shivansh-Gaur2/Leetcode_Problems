class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> occurance;
        occurance[0] = -1;

        int bitmask = 0;
        int maxLen = 0;

        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == 'a'){
                bitmask ^= (1 << 1);
            }
            else if(s[i] == 'e'){
                bitmask ^= (1 << 2);
            }
            else if(s[i] == 'i'){
                bitmask ^= (1 << 3);
            }
            else if(s[i] == 'o'){
                bitmask ^= (1 << 4);
            }
            else if(s[i] == 'u'){
                bitmask ^= (1 << 5);
            }

            if(occurance.find(bitmask) != occurance.end()){
                maxLen = max(maxLen, i - occurance[bitmask]);
            }
            else{
                occurance[bitmask] = i;
            }
        }
        return maxLen;
    }
};