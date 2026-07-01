#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long block = k / (n - 1);
        long long rem = k % (n - 1);

        if (rem == 0)
            cout << block * n - 1 << "\n";
        else
            cout << block * n + rem << "\n";
    }

    return 0;
}