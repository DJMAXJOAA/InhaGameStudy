[4주차 4번] / Top K Frequent Elements / 15분 / https://leetcode.com/problems/top-k-frequent-elements/
순회를 돌면서

문제 접근
1. map으로 빈도를 계산(들어갔는지 확인하고, 검색해서 들어가있으면 value를 1씩 올림)
2. pair<int, int>형 벡터 컨테이너로 내림차순 정렬(value값 기준으로)
3. k의 수만큼 값반환(vector<int>에 넣어서)

개선 사항
1. 우선순위 큐를 사용하면 더 빠르게 풀 수 있음
(생각은 해봤으나, 정렬하기 까다로워서 걍 vector pair 썼음)
2. map보다 unordered_map(해시맵)이 더 빠름
(이 방법을 사용하게 되면, 처음에 빈도 계산시 if 조건문을 걸 필요가 없어짐. 중복도 들어가니까)

새롭게 안 점
1. priority_queue도 pair형으로 넣어진다
2. 컨테이너 삽입에서 insert말고 emplace도 사용 가능 (기능상으론 같은가봄) -> insert(make_pair(1, 2)) == emplace(1, 2)

// Time taken : 15 m 12 s
// Runtime 11ms
// Beats 89.47 % of users with C++
// Memory 14.00MB
// Beats 16.85 % of users with C++

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) == mp.end())
            {
                mp.insert(make_pair(nums[i], 0));
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        vector<pair<int, int>> arr;
        for (auto iter = mp.begin(); iter != mp.end(); iter++)
        {
            arr.push_back(make_pair(iter->second, iter->first));
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> result;
        for (size_t i = 0; i < k; i++)
        {
            result.push_back(arr[i].second);
        }
        return result;
    }
};