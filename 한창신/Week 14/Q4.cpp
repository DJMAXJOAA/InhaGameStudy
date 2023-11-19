#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int quant = s.length();
        int answer = quant;

        if(quant <=1) return 1;

        for(int i=0; i<quant; i++)
        {
            int gap = 0;
            if(i+1<quant)
            {
                while(s[i-gap]==s[i+gap+1])
                {
                    answer++;
                    gap++;
                    if(i-gap<0||i+gap+1>quant)
                        break;
                }
            }

            gap =0;
            if(i+2<quant)
            {
                while(s[i-gap]==s[i+gap+2])
                {
                    answer++;
                    gap++;
                    if(i-gap<0||i+gap+2>quant)
                        break;
                }
            }
        }

        return answer;
    }
};
