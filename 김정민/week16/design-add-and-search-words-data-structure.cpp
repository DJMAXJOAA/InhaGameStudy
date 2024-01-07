class WordDictionary {

public:
    struct Node {
        char val;
        bool isEnd = false;
        Node* children[28];

        Node() {}

        Node(char v) {
            val = v;
            for(int i=0; i<28; i++) { this->children[i] = nullptr; }
        }
    };

public:
    Node* root;

    WordDictionary() {
        root = new Node;
        for(int i=0; i<28; i++) root->children[i] = nullptr;
    }

    int c2i(char c) {
        return c-'a';
    }

    void add(string word, Node* node) {
        if(word.empty()) {
            node->isEnd = true;
            return;
        }

        char cur = word[0];
        int idx = c2i(cur);
        if(node->children[idx] == nullptr) {
            Node* newNode = new Node(cur);
            node->children[idx] = newNode;
        }

        add(word.substr(1), node->children[idx]);
    }

    void addWord(string word) {
        add(word, root);
    }

    bool search(string word, Node *node) {
        if(word.empty()) {
            if(node->isEnd) return true;
            else return false;
        }

        char cur = word[0];
        if(cur == '.') {
            char nxt = word[1];
            string w = word.substr(1);
            bool res = false;
            for(int i=0; i<27; i++) {
                if(node->children[i] != nullptr)
                    res |= search(w, node->children[i]);
            }            
            return res;
        }

        int idx = c2i(cur);
        if(node->children[idx] == nullptr) return false;

        return search(word.substr(1), node->children[idx]);
    }
    
    bool search(string word) {
        return search(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */