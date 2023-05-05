#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    const long long MOD =  (1e9 + 7);

    vector<long long> dp(n);

    for (int i = 0; i != 6 and i != n; ++i)
        dp[i] = 1;
    for (int i = 1; i != n; ++i) {
        for (int k = 1; k <= 6 and i - k >= 0; ++k) {
            dp[i] += dp[i-k];
        }
        dp[i] %= MOD;
    }

    cout << dp[n - 1] << '\n';
}

int main() {
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
