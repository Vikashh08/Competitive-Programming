class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<long long> a;

        for (int x : nums)
            a.push_back(llabs((long long)x));

        sort(a.begin(), a.end());

        long long ans = 0;
        int j = 0;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            while (j < n && a[j] <= 2LL * a[i])
                j++;

            ans += (j - i - 1);
        }

        return ans;
    }
};