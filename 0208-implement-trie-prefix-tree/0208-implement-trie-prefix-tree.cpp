class TrieNode{
    public: 
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0 ; i <= 25; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto ch : word){
            int idx = ch - 'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto ch : word){
            int idx= ch- 'a';
            if(!node->children[idx]){
                return false;
            }
            node= node->children[idx];
        }
        if(!node->isEnd){
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
         TrieNode* node = root;
        for(auto ch : prefix){
            int idx = ch - 'a';
            if(!node->children[idx]){
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */