#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nc, target;
    cin >> nc >> target;

    vector<int> coins(nc);
    for (int i = 0; i != nc; ++i)
        cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<long long> dp(target + 1, numeric_limits<int>::max() - 1);
    dp[0] = 0;

    for (int i = 1; i <= target; ++i) {
        for (auto coin : coins) {
            if (i - coin < 0) 
                break;
            
            dp[i] = min(dp[i], dp[i - coin] + 1); 
        }
    }

    cout << (dp[target] == numeric_limits<int>::max() - 1 ? -1 : dp[target]) << '\n';
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
