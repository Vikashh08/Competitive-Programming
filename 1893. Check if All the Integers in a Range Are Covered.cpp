class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);

        for (auto &r : ranges) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }

        int cover = 0;
        for (int i = 1; i <= 50; i++) {
            cover += diff[i];
            if (i >= left && i <= right && cover == 0)
                return false;
        }

        return true;
    }
};