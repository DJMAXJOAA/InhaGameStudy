class WordDictionary {
private:
    vector<string> savedWord;
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        savedWord.push_back(word);
    }
    
    bool search(string word) {
        
        int count = 0;
        int wordSize = word.size();
        bool correct = false;

        for(int i = 0; i < savedWord.size(); i++)
        {
            if(wordSize == savedWord[i].size())
            {
                int j = 0;
                correct = true;
                while(j < wordSize && correct == true)
                {
                    if(savedWord[i][j] == word[j] || word[j] == '.')
                        correct = true;
                    else
                        correct = false;

                    j++;
                }

                if(correct == true) return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
