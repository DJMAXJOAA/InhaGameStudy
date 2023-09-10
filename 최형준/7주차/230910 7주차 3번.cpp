[7주차 3번] / Product of Array Except Self / 18분 / https://leetcode.com/problems/product-of-array-except-self/

[문제 접근]
사용 알고리즘 = 해시맵
1.  맵에 계산 결과가 포함되어있는지, 안되어있는지 체크
2.  안되어 있으면 multiplication 함수로, 해당 인덱스의 값을 제외한 곱을 계산 후 map에 저장
3.  이미 중복 값이 저장되어있으면 map의 검색 결과 반환
4.  벡터 배열에 저장 후 반환

[개선점]
1.  nums[i]의 범위가 -30~30까지라 미리 결과를 저장해두는 map을 사용했는데, 최악의 경우 O(n^2)까지 갈 수 있음
2.  문제가 풀리기는 했으나 문제가 요구하는 조건인 O(n)에는 해당되지 않음

[다른 풀이 방법]
1. Left, Right로 기준을 두고 계산(O(n))

// Time taken : 18 m 16 s
// Runtime 11ms
// Beats 98.02 % of users with C++
// Memory 24.02MB
// Beats 62.18 % of users with C++

class Solution {
public:
    int multiplication(const vector<int>& nums, int index)
    {
        int result = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == index)
                continue;
            result *= nums[i];
        }
        return result;
    }

    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> result(nums.size());
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = mp.find(nums[i]);
            if (iter == mp.end())
            {
                int mutiple = multiplication(nums, i);
                mp[nums[i]] = mutiple;
                result[i] = mutiple;
            }
            else
            {
                result[i] = iter->second;
            }
        }

        return result;
    }
};


[다른 풀이 방법]
1. Left, Right로 기준을 두고 계산(O(n))

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);

        // left product = 누적 계산(자신의 위치에서 한칸 전까지의 누적 곱셈값)
        // 자신 위치 배열에 계산해둠
        int left_product = 1;
        for (int i = 1; i < n; i++)
        {
            left_product *= nums[i - 1];
            answer[i] = left_product;
        }

        // 자신의 위치 기준 오른쪽 값들의 누적값을 현재 자신의 값에 곱함
        int right_product = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right_product *= nums[i + 1];
            answer[i] *= right_product;
        }

        return answer;
    }
};