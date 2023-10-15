[10주차 1번] / Word Break / https://leetcode.com/problems/word-break/

[문제 접근]
사용 알고리즘 = 트라이, 동적 프로그래밍

[개선점]
1. 트라이 사용할 필요 없이, 동적 프로그래밍만 사용해도 됨

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;

    TrieNode() {};
};

class Trie
{
public:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void Insert(string& word)
    {
        TrieNode* node = root;

        for (char ch : word)
        {
            if (!node->children.count(ch))
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
};

class Solution {
private:
    Trie* trie;

public:
    Solution() : trie(new Trie()) {}

    bool wordBreak(string s, vector<string>& wordDict)
    {
        int wordSize = s.size();
        vector<bool> dp(wordSize + 1, false);
        dp[0] = true;

        for (string& str : wordDict)
        {
            trie->Insert(str);
        }

        for (int i = 1; i <= wordSize; i++)
        {
            TrieNode* node = trie->root;

            for (int j = i; j >= 1; j--)
            {
                if (node->children.count(s[j - 1]))
                {
                    node = node->children[s[j - 1]];
                    if (node->isEndOfWord && dp[j - 1])
                    {
                        dp[i] = true;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return dp[wordSize];
    }
};