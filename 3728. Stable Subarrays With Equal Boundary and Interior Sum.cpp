struct PairHash {
    size_t operator()(const pair<int, long long>& p) const {
        // Simple hash combination using bit shift and XOR
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<long long>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        if (n < 3) return 0;

        // Compute prefix sums: prefix[i] = sum(capacity[0...i-1])
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + capacity[i];
        }

        // Map key: {capacity[l], prefix[l]} -> frequency
        unordered_map<pair<int, long long>, int, PairHash> freq;
        long long stableCount = 0;

        // Iterate right boundary r from index 2 up to n - 1
        for (int r = 2; r < n; ++r) {
            // Add valid left boundary l = r - 2 to map
            int l = r - 2;
            freq[{capacity[l], prefix[l]}]++;

            // For current r, check condition:
            // capacity[l] == capacity[r] AND prefix[l] == prefix[r] - 2 * capacity[r]
            int val_r = capacity[r];
            long long target_prefix = prefix[r] - 2LL * val_r;

            auto it = freq.find({val_r, target_prefix});
            if (it != freq.end()) {
                stableCount += it->second;
            }
        }

        return stableCount;
    }
};