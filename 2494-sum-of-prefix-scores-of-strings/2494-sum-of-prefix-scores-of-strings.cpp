class TrieNode{
    public: 
    TrieNode* children[26];
    int prefixCnt;
    TrieNode(){
        for(int i = 0 ; i < 26; i++){
            children[i] = NULL;
        }
        prefixCnt = 0;

    }
};

class Trie{
    public: 
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string st){
        TrieNode* node = root;
        for(auto ch : st){
            int idx = ch - 'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->prefixCnt++;
        }
    }

    int calculate(string &st){
        int score = 0;
        TrieNode* node = root;
        for(auto ch : st){
            int idx = ch - 'a';
            node = node->children[idx];
            score += node->prefixCnt;
        }
        return score;
    }

};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;
        for(auto it : words){
            trie.insert(it);
        }

        for(auto it : words){
            ans.push_back(trie.calculate(it));
        }
        return ans;
    }
};