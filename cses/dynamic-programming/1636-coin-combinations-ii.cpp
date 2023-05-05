#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nc, target;
    cin >> nc >> target;

    const int MOD = 1e9 + 7;

    vector<int> coins(nc);
    for (int i = 0; i != nc; ++i)
        cin >> coins[i];

    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (auto coin : coins) {
        for (int i = 1; i <= target; ++i) {
            if (i - coin < 0) 
                continue;
            
            dp[i] = (dp[i] + dp[i - coin]) % MOD; 
        }
    }

    cout << dp[target] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
