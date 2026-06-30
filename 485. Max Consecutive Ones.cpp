class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone=0;
        int count=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxone = max(maxone, count);
                count = 0;
            }
        }
        return max(maxone,count);
    }
};