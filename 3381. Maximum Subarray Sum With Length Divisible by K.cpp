class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // smallestPrefixSum[r] = smallest prefix sum whose (index+1)%k = r
        vector<long long> smallestPrefixSum(k, LLONG_MAX);

        long long currentPrefixSum = 0;
        long long maximumSubarraySum = LLONG_MIN;

        // prefix sum before starting any element
        smallestPrefixSum[0] = 0;

        for (int index = 0; index < n; index++) {

            currentPrefixSum += nums[index];

            int remainder = (index + 1) % k;

            // If we have seen a prefix with the same remainder
            if (smallestPrefixSum[remainder] != LLONG_MAX) {
                long long validSubarraySum =
                    currentPrefixSum - smallestPrefixSum[remainder];

                maximumSubarraySum = max(maximumSubarraySum, validSubarraySum);
            }

            // update smallest prefix sum for this remainder
            smallestPrefixSum[remainder] =
                min(smallestPrefixSum[remainder], currentPrefixSum);
        }

        return maximumSubarraySum;
    }
};
