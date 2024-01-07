class Trie {
public:
    struct Node {
        char val;
        map<char, Node*> children;
    };

    Node* root;
    set<string> S;

    Trie() {
        root = new Node();
        for(int i=0; i<27; i++) {
            root->children['a'+i] = nullptr;
        }
    }

    void insert(string &word, Node* node, int idx) {
        if(idx >= word.size()) return;

        char cur = word[idx];
        auto& children = node->children;
        if(children[cur] == nullptr) {
            Node* newNode = new Node();
            newNode->val = cur;
            children[cur] = newNode;
        }

        insert(word, children[cur], idx+1);
    }
    
    void insert(string word) {
        if(S.count(word) == 0) {
            insert(word, root, 0);
            S.insert(word);
        }
    }

    bool traverse(Node* node, string& word, int idx) {
        if(idx >= word.size()) return true;
        
        if(node->children[word[idx]] == nullptr) return false;

        return traverse(node->children[word[idx]], word, idx+1);
    }
    
    bool search(string word) {
        return S.count(word) != 0;
    }
    
    bool startsWith(string prefix) {
        return traverse(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */