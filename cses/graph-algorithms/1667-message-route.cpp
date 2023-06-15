#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> distance(n, -1);

    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int dst = n - 1;
    int src = 0;

    queue<int> q;
    q.push(src);
    distance[src] = 0;
    while (!q.empty() and distance[dst] == -1) {
        auto cur = q.front(); q.pop();
        for (auto child : adj[cur]) {
            if (distance[child] != -1)
                continue;
            q.push(child);
            distance[child] = distance[cur] + 1;
            if (child == dst)
                break;
        }
    }

    if (distance[dst] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> res;
    res.reserve(distance[dst]);
    auto cur = dst;
    res.push_back(cur + 1);
    while (cur) {
        for (auto child : adj[cur]) {
            if (distance[child] == distance[cur] - 1) {
                cur = child;
                res.push_back(child + 1);
                break;
            }
        }
    }
    cout << res.size() << '\n';
    for (auto rit = res.rbegin(); rit != res.rend(); ++rit) {
        cout << *rit << ' ';
    }
    cout << '\n';
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
