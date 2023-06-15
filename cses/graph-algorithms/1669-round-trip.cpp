#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

vector<int> find_cycle(vector<vector<int>>& adj, int n) {
    const int none = -1;

    vector<int> cycle;
    vector<int> prev(n, none);

    for (int i = 0; i != n; ++i) {
        if (prev[i] != none)
            continue;

        stack<int> st;
        st.push(i);
        prev[i] = i;
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();

            for (auto child : adj[cur]) {
                if (prev[child] == none) {
                    prev[child] = cur;
                    st.push(child);
                }
                else if (prev[cur] != child) {
                    cycle.push_back(child);
                    cycle.push_back(cur);
                    while (cur != prev[child]) {
                        cur = prev[cur];
                        cycle.push_back(cur);
                    }
                    cycle.push_back(child);
                    return cycle;
                }
            }
        }
    }

    return cycle;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto cycle = find_cycle(adj,n );

    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << cycle.size() << '\n';
    for (auto node : cycle) {
        cout << node + 1 << ' ';
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
