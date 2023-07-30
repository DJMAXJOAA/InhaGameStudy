class Solution {
public:
    int climbStairs(int n) {
        // if(n > 3)
        //     return climbStairs(n-2) + climbStairs(n-1);
        // else 
        //     return n;

        vector<int> cS(n+1);
        cS[0] = cS[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            cS[i] = cS[i-1] + cS[i-2];
        }

        return cS[n];
    }
};
