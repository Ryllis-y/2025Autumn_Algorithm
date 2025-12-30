#include <bits/stdc++.h>
using namespace std;
const int maxn = 500007;
int node[maxn], edge[maxn << 1], nxt[maxn << 1], cnt = 1;
int depth[maxn], fa[maxn][20], lg[maxn];

void addEdge(int f, int t){
    nxt[cnt] = node[f];
    node[f] = cnt;
    edge[cnt] = t;
    cnt++;
}

void dfs(int u, int father){
    depth[u] = depth[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i <= lg[depth[u]]; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int e = node[u]; e; e = nxt[e]){
        int v = edge[e];
        if (v != father){
            dfs(v, u);
        }
    }
}

int lca(int x, int y){
    if (depth[x] < depth[y]){
        swap(x, y);
    }
    while (depth[x] > depth[y]){
        x = fa[x][lg[depth[x] - depth[y]]];
    }
    if (x == y){
        return x;
    }
    for (int i = lg[depth[x]]; i >= 0; i--){
        if (fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    lg[0] = -1;
    for (int i = 1; i <= n; i++){
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(s, 0);
    while (m--){
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}


