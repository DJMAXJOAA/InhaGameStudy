class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(char c : t)
            map[c]++;


        int counter = t.size();
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int minIdx = 0;

        while(right < s.size())
        {
            if(map[s[right++]]-- >0)
                counter--;
            while(counter == 0)//left와 right 사이에 t의 모든 알파벳이 다 있다
            {
                if(right - left < minLen)
                {
                    minIdx = left;
                    minLen = right - left;
                }
                if(map[s[left++]]++ == 0)//left를 증가시켜 보는데, 0이라면 -> left~right사이에 t의 모든 알파벳이 없다면 
                    counter++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minIdx, minLen);
    }
};