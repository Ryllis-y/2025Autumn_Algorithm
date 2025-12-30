#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e11;
ll st, ed, n, m, cnt = 0;
ll node[10007], edge[10007], nxt[10007], weight[10007], mf[10007], pre[10007];
void addEdge(ll f, ll t, ll w){
    nxt[cnt] = node[f];
    edge[cnt] = t;
    node[f] = cnt;
    weight[cnt] = w;
    cnt++;
}
bool bfs(){
    memset(mf, 0, sizeof(mf));
    queue<ll> q;
    q.push(st);
    mf[st] = inf;
    while (!q.empty()){
        ll cur = q.front(); q.pop();
        for (ll e = node[cur]; e >= 0; e = nxt[e]){
            ll t = edge[e], w = weight[e];
            if (mf[t] == 0 && w > 0){
                mf[t] = min(mf[cur], w);
                pre[t] = e;
                q.push(t);
                if (t == ed) return true;
            }
        }
    }
    return false;
}

ll ek(){
    ll flow = 0;
    while (bfs()){
        int tmp = ed;
        while (tmp != st){
            ll e = pre[tmp];
            weight[e] -= mf[ed];
            weight[e^1] += mf[ed];
            tmp = edge[e^1];
        }
        flow += mf[ed];
    }
    return flow;
}

int main(){
    cin >> n >> m >> st >> ed;
    memset(node, -1, sizeof(node));
    for (int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }
    cout << ek() << endl;
    return 0;
}