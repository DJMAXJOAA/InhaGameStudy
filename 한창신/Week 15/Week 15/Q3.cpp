
/*
https://leetcode.com/problems/unique-paths/
62. Unique Paths
 
 There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

 Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

 The test cases are generated so that the answer will be less than or equal to 2 * 109.

  

 Example 1:


 Input: m = 3, n = 7
 Output: 28
 Example 2:

 Input: m = 3, n = 2
 Output: 3
 Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 1. Right -> Down -> Down
 2. Down -> Down -> Right
 3. Down -> Right -> Down
  

 Constraints:

 1 <= m, n <= 100
 

 class Solution {
 public:
     int uniquePaths(int m, int n) {
         
     }
 };
*/

//TIme Limit Exceeded
/*
class Solution {

    
public:
    bool** traveld;

    int y[2]={0,1};
    int x[2]={1,0};
    
    int maxY;
    int maxX;
    
    int count =0;
    
    int uniquePaths(int m, int n) {
        traveld = new bool*[m];
        maxY=m;
        maxX=n;
        
        for(int i=0 ;i<m;i++)
        {
            traveld[i]=new bool[n];
            for(int j=0; j<n;j++)
                traveld[i][j]=false;
        }
        traveld[0][0]=true;
        CountPath(0,0);
        
        return count;
    }
    
    void CountPath(int crntY, int crntX)
    {
        if(crntY==maxY-1&&crntX==maxX-1)
        {
            count++;
            return;
        }
        
        for(int i=0; i<2;i++)
        {
            int nextY=crntY+y[i];
            int nextX=crntX+x[i];
            if(nextY<0||nextY>=maxY||nextX<0||nextX>=maxX)
                continue;
            if(traveld[nextY][nextX]) continue;
            traveld[nextY][nextX]=true;
            CountPath(nextY, nextX);
            traveld[nextY][nextX]=false;
        }
    }
};


*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int y[2]={-1,0};
        int x[2]={0,-1};

        int** array = new int*[m];
        for(int i=0; i<n;i++)
        {
            array[i]=new int[n];
        }
        array[0][0]=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //array[i][j]=0;
                for(int k=0; k<2;k++)
                {
                    int prvY=i+y[k];
                    int prvX=j+x[k];
                    if(prvY>=0&&prvX>=0)
                    {
                        array[i][j]+=array[prvY][prvX];
                    }
                }
            }
        }
        
        int answer = array[m-1][n-1];
        for(int i=0; i<n;i++)
        {
            delete[] array[i];
        }
        delete[] array;

        return answer;
    }
};

int main()
{
    Solution sol;
    int a= sol.uniquePaths(3, 3);
    int b =0;
    return 0;
}
