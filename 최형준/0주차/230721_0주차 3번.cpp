// =======================================================
// 첫 시도 : 피보나치 수열의 재귀함수로 제출 -> 타임아웃 실패
// 두번째 시도 : 미리 배열에 수를 담아두고, 피보나치 수열 형태로 벡터에 값 대입 후 반환
// =======================================================

class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr;
        arr.push_back(1);
        arr.push_back(2);
        for (int i = 2; i < n; i++)
        {
            arr.push_back(arr[i - 1] + arr[i - 2]);
        }
        return arr[n - 1];
    }
};