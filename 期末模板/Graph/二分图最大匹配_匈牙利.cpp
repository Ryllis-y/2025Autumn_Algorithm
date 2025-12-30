#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node[50007], edge[50007], nxt[50007];
int match[50007], visit[50007];
void addEdge(int i){
    ll a, b;
    cin >> a >> b;
    nxt[i] = node[a];
    node[a] = i;
    edge[i] = b;
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, e;
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++){
        addEdge(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        memset(visit, 0, sizeof(visit));
        ans += dfs(i);
    }
    cout << ans << endl;
    return 0;
}