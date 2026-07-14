class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long top = 0;
        for (int x : grid[0])
            top += x;

        long long bottom = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            top -= grid[0][i];

            ans = min(ans, max(top, bottom));

            bottom += grid[1][i];
        }

        return ans;
    }
};