#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string recipe;
    cin >> recipe;

    int needB = 0, needS = 0, needC = 0;

    for (char ch : recipe) {
        if (ch == 'B') needB++;
        else if (ch == 'S') needS++;
        else needC++;
    }

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    int r;
    cin >> r;

    auto possible = [&](int x) {
        int buyB = max(0LL, needB * x - nb);
        int buyS = max(0LL, needS * x - ns);
        int buyC = max(0LL, needC * x - nc);

        __int128 cost = (__int128)buyB * pb +
                        (__int128)buyS * ps +
                        (__int128)buyC * pc;

        return cost <= r;
    };

    int low = 0, high = 1e13;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (possible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}