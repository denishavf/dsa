#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        parent.reserve(n);
        for (int i = 0; i != n; ++i) {
            parent.push_back(i);
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
        parent[root_a] = root_b;     
    }
};
