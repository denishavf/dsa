#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    ++n;

    const long long infinity = 1e18;//numeric_limits<long long>::max();

    vector<vector<long long>> distance(n, vector<long long>(n, infinity));
    for (int i = 1; i != n; ++i) {
        distance[i][i] = 0; 
    }
    for (int i = 0; i != m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        distance[a][b] = distance[b][a] = min(w, distance[b][a]);
    }

    for (int k = 1; k != n; ++k) {
        for (int i = 1; i != n; ++i) {
            for (int j = 1; j != n; ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for (int i = 0; i != q; ++i) {
        int a, b;
        cin >> a >> b;
        if (distance[a][b] == infinity)
            cout << -1 << '\n';
        else 
            cout << distance[a][b] << '\n';
    }
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
