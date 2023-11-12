class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        int tempMax = (right - left) * min(height[left], height[right]);
        int max = tempMax;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                left++;
                if(height[left-1] < height[left])
                    tempMax = (right - left) * min(height[left], height[right]);
            }
            else
            {
                right--;
                if(height[right+1] < height[right])
                    tempMax = (right - left) * min(height[left], height[right]);
            }

            max = (max < tempMax) ? tempMax : max;
        }

        return max;
    }
};
