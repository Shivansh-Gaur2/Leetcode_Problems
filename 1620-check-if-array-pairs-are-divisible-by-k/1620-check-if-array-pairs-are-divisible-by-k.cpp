class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> ump;

        for (int i = 0; i < arr.size(); i++) {
            ump[((arr[i] % k) + k) % k]++;
        }

        for (auto& it : ump) {
            int remainder = it.first;
            int count = it.second;

            if (remainder == 0) {
                if (count % 2 != 0) {
                    return false;
                }
            } else {
                int complement = k - remainder;
                if (ump[complement] != count) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
