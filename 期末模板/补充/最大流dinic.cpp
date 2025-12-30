#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e11;
ll node[4007], edge[4007], nxt[4007], weight[4007], 
d[4007], h[4007], mf[4007], cur[4007], visit[4007],
a[4007], b[4007], we[4007];
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
    memset(node, -1, sizeof(node));
    cin >> n >> m;
    st = 1, ed = n;
    for (int i = 0; i < m; i++){
        ll w;
        cin >> a[i] >> b[i] >> we[i];
        addEdge(a[i], b[i], we[i]);
        addEdge(b[i], a[i], 0);
    }
    cout << dinic() << " ";
    cnt = 0;
    memset(node, -1, sizeof(node));
    for (int i = 0; i < m; i++){
        addEdge(a[i], b[i], we[i] * (m + 1) + 1);
        addEdge(b[i], a[i], 0);
    }
    cout << dinic() % (m + 1) << endl;
    return 0;

}