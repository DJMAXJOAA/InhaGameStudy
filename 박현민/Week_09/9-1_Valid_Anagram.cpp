/*
    Sort 
    Runtime: 7 ms ~ 16 ms (77.32% ~ 9.88%)
    Memory: 7.5 MB ~ 7.7 MB (35.87% ~ 9.61%)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
		sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

/*
    Hashmap
	Runtime: 5 ms ~ 11 ms (82.59% ~ 47.40%)
	Memory: 7.6 MB ~ 9 MB (21.10% ~ 5.75%)
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;

		unordered_map<char, int> um;

		for (int i = 0; i < s.size(); i++) {
			um[s[i]]++;
		}
		for (int i = 0; i < t.size(); i++) {
			um[t[i]]--;
			if (um[t[i]] < 0) {
				return false;
			}
		}
		return true;
	}
};