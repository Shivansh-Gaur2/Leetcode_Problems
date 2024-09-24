class TrieNode{
public:
    map<char, TrieNode*> child;
    int index;
    TrieNode() {
        index = -1;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word, int& index, vector<string>& wordContainers) {
        TrieNode* node = root;
        for (char ch: word) {
            if (node -> child.find(ch) == node -> child.end()) {
                node -> child[ch] = new TrieNode();
            }
            node = node -> child[ch];
            if (node -> index == -1) {
                node -> index = index;
            } 
            else {
                if (wordContainers[node -> index].size() > word.size()) {
                    node -> index = index;
                }
            }
        }
    }

    int findLongestSuffix(string& word) {
        TrieNode* node = root;
        for (char ch: word) {
            if (node -> child.find(ch) == node -> child.end()) {
                break;
            }
            node = node -> child[ch];
        }
        return node -> index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        
        // insert the words in reverse order
        int min_idx = 0;
        for (int i = 0; i < wordsContainer.size(); i++) {
            string& word = wordsContainer[i];
            reverse(word.begin(), word.end());
            trie.insert(word, i, wordsContainer);

            if (wordsContainer[min_idx].size() > wordsContainer[i].size()) {
                min_idx = i;
            }
        }

        // query the index of longest common suffix
        vector<int> ans;
        for (string& word: wordsQuery) {
            reverse(word.begin(), word.end());
            int idx = trie.findLongestSuffix(word);
            if (idx == -1) {
                idx = min_idx;
            }
            ans.push_back(idx);
        }
        return ans;
    }
};