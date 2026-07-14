class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int value : nums) {
            totalSum += value;
        }

        int remainder = totalSum % p;
        if (remainder == 0) return 0;

        unordered_map<int, int> lastPosition;
        lastPosition[0] = -1;

        long long prefixSum = 0;
        int minimumLength = nums.size();

        for (int index = 0; index < nums.size(); index++) {
            prefixSum = (prefixSum + nums[index]) % p;

            int required = (prefixSum - remainder + p) % p;

            if (lastPosition.count(required)) {
                int length = index - lastPosition[required];
                if (length < minimumLength) {
                    minimumLength = length;
                }
            }

            lastPosition[prefixSum] = index;
        }

        if (minimumLength == nums.size()) return -1;
        return minimumLength;
    }
};
