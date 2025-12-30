#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e11;
ll node[10007], edge[10007], nxt[10007], weight[10007], 
d[10007], h[10007], mf[10007], cur[10007], visit[10007],
a[10007], b[10007], we[10007];
ll n, m, st, ed, cnt = 0;
void addEdge(ll f, ll t, ll w){
    nxt[cnt] = node[f];
    edge[cnt] = t;
    node[f] = cnt;
    weight[cnt] = w;
    cnt++;
}
bool bfs() {
    memset(d, -1, sizeof(d)); 
    queue<ll> q;
    q.push(st);
    d[st] = 0;
    
    while (!q.empty()) {
        ll u = q.front(); 
        q.pop();
        
        for (ll e = node[u]; e != -1; e = nxt[e]) {
            ll v = edge[e];
            if (d[v] == -1 && weight[e] > 0) {  
                d[v] = d[u] + 1;
                q.push(v);
                if (v == ed) return true;
            }
        }
    }
    return false;
}

ll dfs(ll u, ll flow) {  
    if (u == ed) return flow;
    ll sum = 0;
    
    for (ll &e = cur[u]; e != -1; e = nxt[e]) {  
        ll v = edge[e];
        if (d[v] == d[u] + 1 && weight[e] > 0) {
            ll f = dfs(v, min(flow, weight[e]));
            weight[e] -= f;
            weight[e ^ 1] += f;
            sum += f;
            flow -= f;
            if (flow == 0) break;
        }
    }
    if (sum == 0) d[u] = -1; 
    return sum;
}
ll dinic(){
    ll flow = 0;
    while (bfs()){
        memcpy(cur, node, sizeof(cur));
        flow += dfs(st, 1e10);
    }
    return flow;
}
void mincut(ll u){
    visit[u] = 1;
    for (ll e = node[u]; e >= 0; e = nxt[e]){
        ll t = edge[e];
        if (!visit[t] && weight[e]) mincut(t);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        memset(node, -1, sizeof(node));
        cin >> n >> m >> st >> ed;
        //st = 1, ed = n;
        for (int i = 0; i < m; i++){
            ll w;
            cin >> a[i] >> b[i] >> we[i];
            addEdge(a[i], b[i], we[i]);
            addEdge(b[i], a[i], 0);
        }
        cout << dinic() << endl;
        cnt = 0;
    }
    
    return 0;

}