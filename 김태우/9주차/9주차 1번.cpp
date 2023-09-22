// Runtime 20 ms
// Memory 7.9 MB

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        string tempS, tempT;

#ifdef UNICODE
        tempS.assign(s.begin(), s.end());
        tempT.assign(t.begin(), t.end());
#else
        tempS = s;
        tempT = t;
#endif

        map<char, int> m;

        for (int i = 0; i < tempS.size(); i++)
        {
            if (!m[tempS[i]])
                m[tempS[i]] = 1;
            else
                m[tempS[i]]++;
        }

        for (int i = 0; i < tempT.size(); i++)
        {
            if (!m[tempT[i]]) return false;
            else
            {
                m[tempT[i]]--;
                if (m[tempT[i]] == 0)
                    m.erase(tempT[i]);
            }
        }
        if (m.size() == 0) return true;
        else return false;

        //return true;
    }
};

// Runtime 11 ms
// Memory 7.8 MB

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Runtime 7 ms
// Memory 7.7 MB

//use array is the best

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = { 0 };

        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++;
        }

        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--;
        }

        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};