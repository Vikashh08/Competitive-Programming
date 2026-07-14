class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for (auto &trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int passengers = 0;
        for (int x : diff) {
            passengers += x;
            if (passengers > capacity)
                return false;
        }

        return true;
    }
};