#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

int find_max(string_view s) {
    char el = *max_element(s.begin(), s.end());

    return el - '0';
}

void solve() {
    int n;
    cin >> n;
  
    int res = 0;
    while (n) {
        ++res;
        n -= find_max(to_string(n));
    }

    cout << res << '\n';
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
