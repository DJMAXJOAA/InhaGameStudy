class Solution {
    int num[46];
public:
    int climbStairs(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i == 0 || i == 1) num[i] = 1;
            else
            {
                num[i] = num[i - 1] + num[i - 2];
            }
        }

        return num[n];

        //시간초과 남
        //if(n==0 || n==1) return 1;
        //return(climbStairs(n-1) + climbStairs(n-2)); 
    }
};