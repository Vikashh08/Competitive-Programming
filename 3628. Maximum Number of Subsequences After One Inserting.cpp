class Solution {
public:
    long long numOfSubsequences(string s) {

        auto calc = [&](string t) {
            long long cnt = 0;
            long long first = 0;

            for (char c : s) {
                if (c == t[1])
                    cnt += first;
                if (c == t[0])
                    first++;
            }

            return cnt;
        };

        long long leftL = 0;
        long long rightT = count(s.begin(), s.end(), 'T');

        long long base = 0;
        long long bestInsertC = 0;

        for (char c : s) {

            if (c == 'T')
                rightT--;

            if (c == 'C')
                base += leftL * rightT;

            if (c == 'L')
                leftL++;

            bestInsertC = max(bestInsertC, leftL * rightT);
        }

        long long gain = max({
            bestInsertC,
            calc("LC"),
            calc("CT")
        });

        return base + gain;
    }
};