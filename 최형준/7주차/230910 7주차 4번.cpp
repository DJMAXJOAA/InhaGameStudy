[7주차 4번] / Missing Number / 7분 / https://leetcode.com/problems/missing-number/

[문제 접근]
사용 알고리즘 = 그냥 배열에 값 저장
1.  nums 배열을 끝까지 돌면서 numbers 배열에 저장
2.  numbers 배열을 끝까지 돌면서 0인 값 찾기
3.  없으면 size 반환

[개선점]
1.  nums와 같은 사이즈의 공간을 선언하니 공간복잡도가 개망했음
    추가 공간을 안쓰고 푸는 방법을 찾아보기

[다른 풀이 방법]
1.  가우스 합을 이용한 풀이

// Time taken : 7 m 13 s
// Runtime 11ms
// Beats 90.37 % of users with C++
// Memory 18.44MB
// Beats 7.77 % of users with C++

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> numbers(size + 1, 0);

        for (int i = 0; i < size; i++)
        {
            numbers[nums[i]]++;
        }

        for (int i = 0; i < size; i++)
        {
            if (numbers[i] == 0)
                return i;
        }
        return size;
    }
};

// [다른 풀이 방법]
// 1.  가우스 합을 이용한 풀이

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();

        // 가우스 합을 이용해서, 미리 total에 nums의 합을 넣는다
        int total = (n * (n + 1)) / 2;

        for (int num : nums)
        {
            // 배열을 돌면서 해당 nums 인덱스의 값을 모두 뺀다
            total -= num;
        }

        // 모든 값을 빼고 남은 값이 정답이다
        return total;
    }
};