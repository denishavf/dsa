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
    vector<char> color(n, 2);

    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool possible = true;
    for (int i = 0; i != n; ++i) {
        if (color[i] != 2)
            continue;

        stack<int> st;
        st.push(i);
        color[i] = 1;
        while (!st.empty() and possible) {
            auto cur = st.top(); st.pop();
            for (auto child : adj[cur]) {
                if (color[child] == 2) {
                    color[child] = 1 - color[cur];
                    st.push(child);
                } 
                else if (color[child] == color[cur]) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible)
            break;
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i != n; ++i) {
        cout << +color[i] + 1 << ' ';
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
