class Trie {
private:
    vector<string> savedWord;
public:
    Trie() {
    }
    
    void insert(string word) {
        
        savedWord.push_back(word);
    }
    
    bool search(string word) {
        
        for(int i = 0; i < savedWord.size(); i++)
        {
            if(savedWord[i] == word) return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {

        bool correct = false;

        for(int i = 0; i < savedWord.size(); i++)
        {
            if(savedWord[i][0] == prefix[0] && savedWord[i].size() >= prefix.size())
            {
                int j = 0;
                correct = true;
                while(j < prefix.size() && correct == true)
                {
                    if(savedWord[i][j] == prefix[j])    
                        correct = true;
                    else    
                        correct = false;

                    j++;
                }
            }

            if(correct == true)
                return true;
        }

        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
