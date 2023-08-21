// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ret;

        int l = 0;
        int t = 0;
        int r = col;
        int b = row;

        int rp = 0;
        int cp = 0;

        while(ret.size() < row * col)
        {
            while(cp < r) ret.push_back(matrix[rp][cp++]);
            cp--;
            rp++;
            r--;

            while(rp < b) ret.push_back(matrix[rp++][cp]);
            rp--;
            cp--;
            b--;

            while(l <= cp) ret.push_back(matrix[rp][cp--]);
            cp++;
            rp--;
            l++;

            while(t < rp) ret.push_back(matrix[rp--][cp]);
            rp++;
            cp++;
            t++;
        }

        return ret;
    }
};