class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> box;
        int maxcnt = 0;
        for (auto a : nums)
            box.insert(a);

        while (box.size() != 0) {
            int number = *box.begin();
            box.erase(number);
            int cnt = 1;
            // find left
            int left = number;
            while (box.find(--left) != box.end()) {
                cnt++;
                box.erase(left);
            }

            // find right
            int right = number;
            while (box.find(++right) != box.end()) {
                cnt++;
                box.erase(right);
            }
            maxcnt = max(cnt, maxcnt);

        }
        return maxcnt;
    }
};