class TrieNode {
public:
    TrieNode* children[26] = {};
    vector<string> suggestions;
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
            if (node->suggestions.size() < 3) node->suggestions.push_back(word);
        }
    }
    
    vector<string> searchPrefix(string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) return {};
            node = node->children[idx];
        }
        return node->suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        sort(products.begin(), products.end());
        for (string& product : products) trie.insert(product);
        
        vector<vector<string>> result;
        string prefix;
        for (char ch : searchWord) {
            prefix += ch;
            result.push_back(trie.searchPrefix(prefix));
        }
        return result;
    }
};
