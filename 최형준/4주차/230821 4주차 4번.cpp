[4���� 4��] / Top K Frequent Elements / 15�� / https://leetcode.com/problems/top-k-frequent-elements/
��ȸ�� ���鼭

���� ����
1. map���� �󵵸� ���(������ Ȯ���ϰ�, �˻��ؼ� �������� value�� 1�� �ø�)
2. pair<int, int>�� ���� �����̳ʷ� �������� ����(value�� ��������)
3. k�� ����ŭ ����ȯ(vector<int>�� �־)

���� ����
1. �켱���� ť�� ����ϸ� �� ������ Ǯ �� ����
(������ �غ�����, �����ϱ� ��ٷο��� �� vector pair ����)
2. map���� unordered_map(�ؽø�)�� �� ����
(�� ����� ����ϰ� �Ǹ�, ó���� �� ���� if ���ǹ��� �� �ʿ䰡 ������. �ߺ��� ���ϱ�)

���Ӱ� �� ��
1. priority_queue�� pair������ �־�����
2. �����̳� ���Կ��� insert���� emplace�� ��� ���� (��ɻ����� ��������) -> insert(make_pair(1, 2)) == emplace(1, 2)

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