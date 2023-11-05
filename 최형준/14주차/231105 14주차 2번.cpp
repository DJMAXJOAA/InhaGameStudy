[14주차 2번] / 3Sum / 1시간 57분 / https://leetcode.com/problems/3sum/description/

[문제 접근]
사용 알고리즘 = 투 포인터, 정렬 : O(n^2) + O(n log n), O(n)
1. 값과 인덱스 쌍을 기억하는 배열
2. 값을 하나 설정(low) + 투 포인터로 범위를 조절하여 삼중 조합을 찾음
3. set 배열에 대입해서, 중복 배열 대입을 미리 차단

[이슈 및 개선점]
1. vector<int, int> pair 배열로 비교할 필요 없이, 중복된 요소는 제거하거나 무시시키면 시간 + 공간 복잡도를 개선시킬 수 있음

[다른 풀이 방법]
1. 투 포인터 : O(n^2), O(1)
2. 해시 맵 : O(n^2), O(n)
3. 브루트 포스 : O(n^3), O(1)

Time taken : 42 m 56 s
Runtime 2151ms
Beats 5.01 % of users with C++
Memory 306.18MB
Beats 5.06 % of users with C++

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> resultSet;

        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < nums.size(); i++)
        {
            sortedNums.push_back(make_pair(nums[i], i));
        }
        sort(sortedNums.begin(), sortedNums.end());

        int prePointer, postPointer;
        int lowValue, midValue, highValue;
        int size = sortedNums.size();
        for (int i = 0; i < size; i++)
        {
            prePointer = i + 1;
            postPointer = size - 1;

            lowValue = sortedNums[i].first * -1;

            while (postPointer > prePointer)
            {
                midValue = sortedNums[prePointer].first;
                highValue = sortedNums[postPointer].first;

                int sum = midValue + highValue;
                if (lowValue == sum)
                {
                    vector<int> temp
                    { -lowValue, midValue, highValue };
                    sort(temp.begin(), temp.end());
                    resultSet.insert(temp);
                }

                if (lowValue < sum)
                {
                    postPointer--;
                }
                else
                {
                    prePointer++;
                }
            }
        }

        vector<vector<int>> result;
        for (auto iter : resultSet)
        {
            result.push_back(iter);
        }
        return result;
    }
};


[다른 풀이 방법]
투 포인터 : O(n ^ 2), O(1)
1. 입력 배열을 직접 정렬
2. 중복 처리를 위해 조건을 둬서 건너뛰게 설정 (set 사용 X)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i])
                twoSumII(nums, i, result);
        return result;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            }
            else if (sum > 0) {
                --hi;
            }
            else {
                res.push_back({ nums[i], nums[lo++], nums[hi--] });
                while (lo < hi && nums[lo] == nums[lo - 1])
                    ++lo;
            }
        }
    }
};


해시 맵 : O(n ^ 2), O(n)
1. 두 수의 합을 해시맵의 key로 설정
2. 배열을 순회하면서 -nums[i]를 해시맵에서 검색
3. 중복을 관리해야 하기 때문에 풀이가 까다로움 + 추가 공간 사용
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end()); // 정렬
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 중복 값 건너뛰기
            unordered_map<int, int> hash_map;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) continue; // 중복 값 건너뛰기
                int complement = -nums[i] - nums[j];
                if (hash_map.count(complement)) {
                    result.push_back({ nums[i], nums[j], complement });
                    hash_map.erase(complement); // 중복 삼중 조합을 방지하기 위함
                }
                else {
                    hash_map[nums[j]] = j;
                }
            }
        }
        // 결과에서 중복된 삼중 조합을 제거
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};


브루트 포스 : O(n ^ 3), O(1)
1. 모든 가능한 삼중 조합을 검사
2. 풀이가 직관적이지만 매우 비효율적
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 정렬하여 중복 처리를 쉽게 만듦
        for (int i = 0; i < nums.size(); ++i) {
            // 중복된 값 건너뛰기
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                // 중복된 값 건너뛰기
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1; k < nums.size(); ++k) {
                    // 중복된 값 건너뛰기
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({ nums[i], nums[j], nums[k] });
                    }
                }
            }
        }
        return result;
    }
};

