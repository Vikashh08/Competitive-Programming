class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(2, INT_MAX)));

        using T = tuple<int, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0}); // time, x, y, parity

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, x, y, parity] = pq.top();
            pq.pop();

            if (time > dist[x][y][parity])
                continue;

            if (x == m - 1 && y == n - 1)
                return time;

            int cost = (parity == 0 ? 1 : 2);

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newTime = max(time, moveTime[nx][ny]) + cost;

                if (newTime < dist[nx][ny][parity ^ 1]) {
                    dist[nx][ny][parity ^ 1] = newTime;
                    pq.push({newTime, nx, ny, parity ^ 1});
                }
            }
        }

        return -1;
    }
};