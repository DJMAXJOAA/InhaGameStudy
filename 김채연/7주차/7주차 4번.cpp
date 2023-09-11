//easy

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // >> : 런타임 오류

        //sort(nums.begin(), nums.end()); //정렬하고

        ////1차이 안나면 범인
        //for (int i = 0; i < nums.size(); i++)
        //{
        //    if (nums[i] + 1 != nums[i + 1])
        //    {
        //        return nums[i + 1];
        //    }
        //}

        // << :

        //const int n = nums.size()+1;
        int arr[10000] = { 0 };

        for (int i = 0; i <= nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == nums[j])
                {
                    arr[i] = 1;
                }
            }
        }

        for (int i = 0; i <= nums.size(); i++)
        {
            if (arr[i] != 1)
                return i;
        }

        return 0;

    }
};