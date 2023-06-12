#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> height;

public:
    DSU(int n) {
        parent.reserve(n);
        height.reserve(n);
        for (int i = 0; i != n; ++i) {
            parent.push_back(i);
            height.push_back(0);
        }
    }

    int find(int node) {
        while (node != parent[node] and parent[node] != parent[parent[node]]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return parent[node];
    }

    void unite(int a, int b) {
        auto root_a = find(a);
        auto root_b = find(b);
        
        if (height[root_a] > height[root_b]) {
            parent[root_b] = root_a;
            height[root_a] = max(height[root_a], height[root_b] + 1);
        } else {
            parent[root_a] = root_b;
            height[root_b] = max(height[root_b], height[root_a] + 1);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i != m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        dsu.unite(node1 - 1, node2 - 1);
    }

    unordered_set<int> roots;
    for (int i = 0; i != n; ++i) {
        roots.insert(dsu.find(i));
    }

    int s = roots.size();
    std::cout << s - 1 << '\n';
    if (s == 1)
        return;
    auto it_b = roots.begin();
    auto it = next(it_b);
    while (it != roots.end()) {
        std::cout << *it_b + 1 << ' ' << *it + 1 << '\n';
        ++it;
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
