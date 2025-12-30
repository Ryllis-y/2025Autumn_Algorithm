#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200007;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
int parent[MAXN], sz[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    return true;
}

signed main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n + 1; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    sort(edges.begin(), edges.end());
    
    int ans = 0;
    for (auto& e : edges) {
        if (unite(e.u, e.v)) {
            ans += e.w;
        }
    }
    
    cout << ans << endl;
    return 0;
}