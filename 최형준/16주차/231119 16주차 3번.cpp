[16주차 3번] / Implement Trie(Prefix Tree) / https://leetcode.com/problems/implement-trie-prefix-tree/description/

[문제 접근]
1. 트라이 구현을 위해 노드 구조체 선언
2. 해시맵으로 문자와 문자를 연결시켜줌
3. 단어 체크용으로 isEnd 불 변수 추가

Time taken : 46 m 5 s
Runtime 62ms
Beats 36.02 % of users with C++
Memory 42.20MB
Beats 84.42 % of users with C++

struct Node
{
    unordered_map<char, Node*> children;
    bool isEnd;
    Node() : isEnd(false) {}
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++)
        {
            auto iter = node->children.find(word[i]);
            if (iter == node->children.end())
            {
                node->children.insert(make_pair(word[i], new Node()));
            }
            node = node->children[word[i]];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* search = root;

        for (int i = 0; i < word.size(); i++)
        {
            auto iter = search->children.find(word[i]);
            if (iter == search->children.end())
            {
                return false;
            }
            else
            {
                search = search->children[word[i]];
            }
        }

        return search->isEnd;
    }

    bool startsWith(string prefix) {
        Node* search = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            auto iter = search->children.find(prefix[i]);
            if (iter == search->children.end())
            {
                return false;
            }
            else
            {
                search = search->children[prefix[i]];
            }
        }

        return true;
    }
};
