#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nc, target;
    cin >> nc >> target;

    const int MOD = 1e9 + 7;

    vector<int> coins(nc);
    for (int i = 0; i != nc; ++i)
        cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; ++i) {
        for (auto coin : coins) {
            if (i - coin < 0) 
                break;
            
            dp[i] += dp[i - coin]; 
        }
        dp[i] %= MOD;
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
