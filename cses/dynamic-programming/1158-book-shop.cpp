#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

void solve() {
    int n, max_price;
    cin >> n >> max_price;

    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i != n; ++i) 
        cin >> prices[i];
    for (int i = 0; i != n; ++i) 
        cin >> pages[i];

    vector<int> dp(max_price + 1);

    for (int i = 1; i <= n; ++i) {
        for (int price = max_price; price >= 0; --price) {
            if (prices[i-1] > price) {
                break;
            }
            dp[price] = max(
                dp[price], 
                dp[price - prices[i-1]] + pages[i-1]
            );
        }
    }

    cout << dp[max_price] << '\n';
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
