class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        long long int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (pow(mid, 2) == x) {
                return (mid);
            }
            if (pow(mid, 2) < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};