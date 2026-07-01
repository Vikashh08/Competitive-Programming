#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll S;
    cin >> n >> S;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    auto check = [&](int k) {
        vector<ll> cost(n);
        for (int i = 1; i <= n; i++)
            cost[i - 1] = a[i] + 1LL * i * k;

        sort(cost.begin(), cost.end());

        ll sum = 0;
        for (int i = 0; i < k; i++)
            sum += cost[i];

        return sum;
    };

    int low = 0, high = n;
    int ansK = 0;
    ll ansCost = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        ll curCost = check(mid);

        if (curCost <= S) {
            ansK = mid;
            ansCost = curCost;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ansK << " " << ansCost << "\n";

    return 0;
}