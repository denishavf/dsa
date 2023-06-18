#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
   
    const long long infinity = numeric_limits<long long>::max();

    vector<vector<pair<int,long long>>> adj(n + 1);
    vector<bool> processed(n + 1, false);
    vector<long long> distance(n + 1, infinity);

    for (int i = 0; i != m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    distance[1] = 0;

    while (!pq.empty()) {
        auto a = pq.top().second;
        pq.pop();

        if (processed[a])
            continue;
        processed[a] = true;

        for (auto u : adj[a]) {
            auto b = u.first;
            auto w = u.second;

            if (distance[b] > distance[a] + w) {
                distance[b] = distance[a] + w;
                pq.push({distance[b], b});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << distance[i] << ' ';
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
