class Trie {
public:
    unordered_map<string, int> table;
    /*
    0: none
    1: prefix
    2: whole word
    */

    Trie() {

    }

    // O(n) word length: n
    void insert(string word) {
        string prefix = "";
        for (int i = 1; i < word.length(); i++) {
            prefix = word.substr(0, i);
            if (table.find(prefix) == table.end()) {
                table[prefix] = 1;
            }
        }
        table[word] = 2;
    }

    // O(1)
    bool search(string word) {
        if (table.find(word) != table.end()) {
            if (table[word] == 2)
                return true;
        }
        return false;
    }

    // O(1)
    bool startsWith(string prefix) {
        if (table.find(prefix) != table.end())
            return true;
        return false;
    }
};