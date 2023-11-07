class Solution {
public
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string answer = s.substr(0,1);

        for(int i = 0; is.size();i++)
        {
            string odd = expand(i,i,s);
            string even = expand(i,i+1,s);
            if(odd.size()answer.size())
                answer = odd;
            if(even.size()answer.size())
                answer = even;
        }
        return answer;
    }

    string expand(int left, int right, string& s)
    {
        while(left=0 && rights.size()&& s[left]==s[right])
        {
            left--;right++;
        }
        return s.substr(left+1, right-left-1);
    }
};