class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> diff;

        for (auto &s : segments) {
            diff[s[0]] += s[2];
            diff[s[1]] -= s[2];
        }

        vector<vector<long long>> ans;

        long long cur = 0;
        long long prev = 0;
        bool first = true;

        for (auto &[pos, val] : diff) {
            if (!first && cur > 0 && prev < pos) {
                ans.push_back({prev, pos, cur});
            }

            cur += val;
            prev = pos;
            first = false;
        }

        return ans;
    }
};