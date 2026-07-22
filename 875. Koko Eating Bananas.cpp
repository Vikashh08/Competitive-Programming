class Solution {
    bool fun(vector<int> piles, int k, int h) {
        long long t = 0;
        for (int i = 0; i < piles.size(); i++) {
            t += (piles[i] + k - 1) / k;
        }
        if (t <= h) {
            return true;
        } else {
            return false;
        }
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxel = *max_element(piles.begin(), piles.end());
        int l = 1, r = maxel, mid, ans = r;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (fun(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};