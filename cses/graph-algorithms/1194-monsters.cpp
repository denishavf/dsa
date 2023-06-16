#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int i = 0;
    int j = 0;

    Pos& operator=(const Pos& other) {
        i = other.i;
        j = other.j;
        return *this;
    }
};

Pos operator+(const Pos& lhs, const Pos& rhs) {
    return {lhs.i + rhs.i, lhs.j + rhs.j};
}

const char wall = '#';
const char road = '.';
const char M = 'M';
const char A = 'A';
const Pos dirs[4] = {{1,0},{-1,0},{0,-1},{0,1}};


bool check(vector<vector<char>>& grid, Pos p, int h, int w) {
    if (p.i < 0 or p.j < 0 or p.i >= h or p.j >= w)
        return false;
    if (grid[p.i][p.j] == wall)
        return false;
    return true;
}

Pos bfs(vector<vector<char>>& grid, vector<vector<int>>& distance_m, vector<vector<int>>& distance_a, queue<Pos>& q, bool monster) {
    int h = grid.size();
    int w = grid[0].size();
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto& dir : dirs) {
            auto child = cur + dir;
            if (!check(grid, child, h, w))
                continue;

            // monster dfs
            if (monster) {
                if (distance_m[child.i][child.j] > distance_m[cur.i][cur.j] + 1) {
                    distance_m[child.i][child.j] = distance_m[cur.i][cur.j] + 1;
                    q.push(child);
                }
            }
            // A dfs
            else {
                if (distance_m[child.i][child.j] <= distance_a[cur.i][cur.j] + 1)
                    continue;
                if (distance_a[child.i][child.j] <= distance_a[cur.i][cur.j] + 1)
                    continue;
                distance_a[child.i][child.j] = distance_a[cur.i][cur.j] + 1;
                if (child.i == 0 or child.j == 0 or child.i == h-1 or child.j == w-1)
                    return child;
                q.push(child);
            }

        }
    }

    return {-1, -1};
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> distance_m(h, vector<int>(w, 1e7));
    vector<vector<int>> distance_a(h, vector<int>(w, 1e7));

    Pos start_pos{};
    queue<Pos> q;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i != h; ++i) {
        for (int j = 0; j != w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == M) {
                q.push({i, j});
                distance_m[i][j] = 0;
            }
            else if (grid[i][j] == A) { 
                start_pos = {i, j};
                distance_a[i][j] = 0;
            }
        }
    }

    { // dumb way to check if solved from the start
        if (start_pos.i == 0 or start_pos.j == 0 
                or start_pos.i == h-1 or start_pos.j == w-1) {
            cout << "YES\n0\n";
            return;
        }
    }

    // fill up monster distances
    bfs(grid, distance_m, distance_a, q, true);

    q.push({start_pos.i, start_pos.j});
    auto res_pos = bfs(grid, distance_m, distance_a, q, false);

    if (res_pos.i == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    // bakctrack answer
    string ans;
    auto cur_dst = distance_a[res_pos.i][res_pos.j];
    while (cur_dst) {   
        --cur_dst;
        for (auto dir : dirs) {
            auto cur_pos = res_pos + dir;
            if (!check(grid, cur_pos,h, w)) {
                continue;
            }
            if (distance_a[cur_pos.i][cur_pos.j] == cur_dst) {
                if (dir.i == 0 and dir.j == 1)
                    ans.push_back('L');
                if (dir.i == 0 and dir.j == -1)
                    ans.push_back('R');
                if (dir.i == 1 and dir.j == 0)
                    ans.push_back('U');
                if (dir.i == -1 and dir.j == 0)
                    ans.push_back('D');
                res_pos.i = cur_pos.i; res_pos.j = cur_pos.j;
                break;
            }
        }
    }
    reverse(begin(ans), end(ans));
    cout << ans.size() << '\n';
    cout << ans << '\n';
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
