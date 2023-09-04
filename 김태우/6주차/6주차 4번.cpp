class Solution {
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size()) // size problem
        {
            return "";
        }
        unordered_map<char, int> map; // better than map, dafault initalize with 0
        for (int i = 0; i < t.size(); i++) // add chars of t
        {
            map[t[i]]++;
        }
        int count = 0, start = 0, min_length = INT_MAX, min_start = 0;
        for (int end = 0; end < s.size(); end++)
        {
            if (map[s[end]] > 0)
            {
                count++;
            }

            map[s[end]]--;
            if (count == t.length()) //found all t letters
            {
                while (start < end && map[s[start]] < 0) // find next start point
                {
                    map[s[start]]++, start++;
                }
                if (min_length > end - start) {
                    min_length = end - (min_start = start) + 1; // this is possible
                }
                map[s[start++]]++; // move start point
                count--;
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length);
        //return substring

    }
};