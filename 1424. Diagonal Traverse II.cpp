class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        int maxDiag = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);
                maxDiag = max(maxDiag, i + j);
            }
        }

        vector<int> ans;

        for (int d = 0; d <= maxDiag; d++) {
            auto &v = mp[d];
            for (int i = v.size() - 1; i >= 0; i--) {
                ans.push_back(v[i]);
            }
        }

        return ans;
    }
};