class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> dict;
        int longestPrefix = 0;

        for (int i = 0; i < arr1.size(); i++) {
            string numStr = to_string(arr1[i]);
            string prefix = "";
            for (int j = 0; j < numStr.size(); j++) {
                prefix += numStr[j];
                dict.insert(prefix); 
            }
        }

        for (int i = 0; i < arr2.size(); i++) {
            string numStr = to_string(arr2[i]);
            string prefix = "";
            for (int j = 0; j < numStr.size(); j++) {
                prefix += numStr[j];
                if (dict.find(prefix) != dict.end()) {
                    longestPrefix = max(longestPrefix, static_cast<int>(prefix.size())); 
                }
                else {
                    break;
                }
            }
        }

        return longestPrefix;
    }
};
