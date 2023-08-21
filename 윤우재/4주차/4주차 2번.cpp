class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26,0);
        int maxCnt = 0; int beg = 0;
        for(int i = 0; i<s.size();i++)
        {
            //알파벳들에 대해서 나온 횟수를 카운팅
            //가장 많이 나온 카운트를 저장
            maxCnt = max(maxCnt, ++counts[s[i]-'A']);
            //maxCnt + k가 두 포인터 사이의 거리보다 더 작다 -> 거리를 감당할 수 없으면 beg포인트를 오른쪽으로 옮기고, beg포인트가 가리켰던 값을 하나 낮춤
            if(maxCnt + k < i - beg + 1)
                counts[s[beg++] - 'A']--;
                
        }
        return s.length() - beg;
    }
};