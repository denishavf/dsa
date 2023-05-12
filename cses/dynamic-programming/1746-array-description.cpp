#include <bits/stdc++.h>

using namespace std;

void solve() {
    const int MOD = 1e9 + 7;

    int n, max_val;
    cin >> n >> max_val;

    vector<vector<int>> dp(n, vector<int>(max_val));

    int x;
    cin >> x;
    if (x == 0) {
        fill(dp[0].begin(), dp[0].end(), 1); 
    } 
    else {
        dp[0][x-1] = 1; 
    }

    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (x == 0) {
            for (int j = 0; j != max_val; ++j) {
                for (int c : {j-1, j, j+1}) {
                    if (c >= 0 and c < max_val) {
                        dp[i][j] += dp[i-1][c];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        else {
            int j = x-1;
            for (int c : {j-1, j, j+1}) {
                if (c >= 0 and c < max_val) {
                    dp[i][j] += dp[i-1][c];
                    dp[i][j] %= MOD;
                }
            }
        }
    }


    //int ans = reduce(dp[n-1].begin(), dp[n-1].end(), 0);
    int ans = 0;
    for (auto c : dp[n-1]) 
        ans = (ans + c) % MOD;
    cout << ans << '\n';
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
