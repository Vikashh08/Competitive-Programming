class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if (time > dist[x][y])
                continue;

            if (x == m - 1 && y == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newTime = max(time, moveTime[nx][ny]) + 1;

                if (newTime < dist[nx][ny]) {
                    dist[nx][ny] = newTime;
                    pq.push({newTime, {nx, ny}});
                }
            }
        }

        return -1;
    }
};