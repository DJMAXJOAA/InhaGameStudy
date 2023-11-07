class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==1)return 1;
        int answer = 0;

        for(int i = 0; i<s.size();i++)
        {
            expand(i,i,s,answer);
            expand(i,i+1,s,answer);
        }
        return answer;
    }
    void expand(int left, int right, string& s, int& cnt)
    {
        while(left>=0 && right<s.size()&& s[left]==s[right])
        {
            left--; right++;
            cnt++;
        }
    }
};