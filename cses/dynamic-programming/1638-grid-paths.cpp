#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    const int trap = -1;

    vector<vector<long>> grid(n, vector<long>(n));

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            char cell;
            cin >> cell;

            if (cell == '*')
                grid[i][j] = trap;
        }
    }
    if (grid[0][0] == trap or grid[n-1][n-1] == trap) {
        cout << "0\n";
        return;
    }

    grid[0][0] = 1;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) { 
            if (grid[i][j] == trap)
                continue;
            if (i + 1 < n and grid[i + 1][j] != trap)
                grid[i + 1][j] = (grid[i+1][j] + grid[i][j]) % MOD;
            if (j + 1 < n and grid[i][j + 1] != trap)
                grid[i][j + 1] = (grid[i][j+1] + grid[i][j]) % MOD;
        }
    }

    cout << grid[n-1][n-1] << '\n';
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
