[16ÁÖÂ÷ 4¹ø] / Design Add and Search Words Data Structure / https://leetcode.com/problems/design-add-and-search-words-data-structure/

struct Node
{
	bool isEnd;
	unordered_map<char, Node*> children;

	Node() : isEnd(false) {}
};

class WordDictionary {
private:
	Node* root;

public:
	WordDictionary() {
		root = new Node();
	}

	void addWord(string word) {
		Node* node = root;
		for (auto c : word)
		{
			auto iter = node->children.find(c);
			if (iter == node->children.end())
			{
				node->children.insert(make_pair(c, new Node()));
			}
			node = node->children[c];
		}

		node->isEnd = true;
		return;
	}

	bool search(string word) {
		return searchIndex(word, root, 0);
	}

	bool searchIndex(string& word, Node* current, int index)
	{
		if (current == nullptr)
			return false;

		if (index >= word.size())
			return current->isEnd;

		if (word[index] == '.')
		{
			for (auto& itr : current->children)
			{
				if (searchIndex(word, itr.second, index + 1))
					return true;
			}
			return false;
		}
		else
		{
			auto iter = current->children.find(word[index]);
			if (iter == current->children.end())
			{
				return false;
			}
		}
		return searchIndex(word, current->children[word[index]], index + 1);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */