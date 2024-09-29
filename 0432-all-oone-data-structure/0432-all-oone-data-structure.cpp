#include <unordered_map>
#include <string>
#include <limits>

class AllOne {
public:
    std::unordered_map<std::string, int> ump;

    AllOne() {
    }
    
    void inc(std::string key) {
        ump[key]++;
    }
    
    void dec(std::string key) {
        if (ump.find(key) != ump.end()) {
            if (ump[key] == 1) {
                ump.erase(key);
            } else {
                ump[key]--;
            }
        }
    }
    
    std::string getMaxKey() {
        if (ump.empty()) {
            return ""; // Return empty string if map is empty
        }
        std::string maxKey = "";
        int maxCount = 0;

        for (const auto& it : ump) {
            if (it.second > maxCount) {
                maxCount = it.second;
                maxKey = it.first;
            }
        }
        return maxKey;
    }
    
    std::string getMinKey() {
        if (ump.empty()) {
            return ""; // Return empty string if map is empty
        }
        std::string minKey = "";
        int minCount = std::numeric_limits<int>::max();

        for (const auto& it : ump) {
            if (it.second < minCount) {
                minCount = it.second;
                minKey = it.first;
            }
        }
        return minKey;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * std::string param_3 = obj->getMaxKey();
 * std::string param_4 = obj->getMinKey();
 */
