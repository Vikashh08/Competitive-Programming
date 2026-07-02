class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        
        int r = rStart, c = cStart;
        ans.push_back({r, c});

        int steps = 1;
        int dir = 0;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        while (ans.size() < rows * cols) {
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < steps; i++) {
                    r += dr[dir];
                    c += dc[dir];

                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                        ans.push_back({r, c});
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }

        return ans;
    }
};