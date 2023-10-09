//모든 데이터를 set에 넣어주고

//제약조건인 O(N) 탐색을 위해, 확인할때마다 erase 해주면서 최댓값을 구한다.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> set;
        int max = 0;
        for (int n : nums)
            set.insert(n);

        for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
        {
            int val = *it;
            int val_end = val;
            int count;
            while (set.find(++val_end) != set.end()) {
                set.erase(val_end);
            }
            while (set.find(--val) != set.end()) {
                set.erase(val);
            }
            count = val_end - val - 1;
            max = max < count ? count : max;
        }
        return max;
    }
};