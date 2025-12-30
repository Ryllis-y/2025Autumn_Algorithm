#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt = 1;
int a[1007], p[1007];
ll node[50007], edge[50007], nxt[50007];
int match[50007], visit[50007];    
void addEdge(ll x, ll y){
    nxt[cnt] = node[x];
    node[x] = cnt;
    edge[cnt++] = y;
}
int dfs(ll u){
    for (int e = node[u]; e; e = nxt[e]){
        int v = edge[e];
        if (visit[v]) continue;
        visit[v] = 1;
        if (!match[v] || dfs(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = n + 1; i <= 2 * n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) cin >> p[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            if (a[i] >= p[j] && a[j] >= p[i])
                addEdge(i, j);      
        }
    }
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        memset(visit, 0, sizeof(visit));
        ans += dfs(u);
    }
    cout << ans << endl;
    return 0;
}
