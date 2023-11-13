class Solution {
public:
    int maxArea(vector<int>& height) {
        //j-i * min(height[j], height[i])가 가장 큰 경우의 i, j를 찾기

        int i = 0; int j = height.size()-1;
        
        int area = 0;
        while(i<j)
        {
            int h = min(height[i],height[j]);
            int curArea = (j - i) * h;
            if(curArea>area)
                area = curArea;
            if(height[i]<height[j])
            {
                i++;
            }
            else
                j--;
        }
        return area;
    }

    
};