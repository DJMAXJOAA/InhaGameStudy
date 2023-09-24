// Runtime 81 ms
//Memory 68 MB

//O(1) memory, no function

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

// Runtime 107 ms
// Memory 76 MB

//O(n) memory, array access/ function call

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums)));
        dp[0][0] = dp[1][0] = nums[0];
        for (int i = 1; i < size(nums); i++) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }
        return dp[0].back();
    }
};

// Runtime 88 ms
// Memory 68.1 MB

// Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int curSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            curSum = max(nums[i], nums[i] + curSum);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};

// Runtime 129 ms
// Memory 68.2 MB

//divided and conquer
//O(nlongn)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums) - 1);
    }
    int maxSubArray(vector<int>& A, int L, int R) {
        if (L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for (int i = mid - 1, curSum = 0; i >= L; i--)
            curSum += A[i],
            leftSum = max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for (int i = mid + 1, curSum = 0; i <= R; i++)
            curSum += A[i],
            rightSum = max(rightSum, curSum);
        // return max of 3 cases 
        return max({ maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R), leftSum + A[mid] + rightSum });
    }
};