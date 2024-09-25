class TrieNode{
    public : 
    TrieNode* children[2];
    TrieNode(){
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie{
    public: 
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->children[bit]){
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaxXor(int num){
        int maxXor = 0;
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            int oppBit = 1 - bit;
            if(node->children[oppBit]){
                maxXor |= (1 << i);
                node=node->children[oppBit];
            }
            else{
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto num : nums){
            trie.insert(num);
        }
        int maxXor = 0;

        for(auto num : nums){
            maxXor = max(maxXor, trie.findMaxXor(num));
        }
        return maxXor;
    }
};