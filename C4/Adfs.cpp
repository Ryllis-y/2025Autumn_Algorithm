#include <bits/stdc++.h> 
using namespace std;     

const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;

int n, m;
int node[MAXN], edge[MAXM * 2], nxt[MAXM * 2];
int idx;
bool visit[MAXN];

void addEdge(int u, int v) {
    edge[idx] = v;
    nxt[idx] = node[u];
    node[u] = idx++;
}

void dfs(int u) {
    visit[u] = true;
    for (int e = node[u]; e; e = nxt[e]) {
        int v = edge[e];
        if (!visit[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n >> m;

    idx = 1; 

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u); // 无向图建两条边
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}