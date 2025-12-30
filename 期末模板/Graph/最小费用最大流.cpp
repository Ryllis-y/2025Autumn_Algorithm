#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e11;
ll st, ed, n, m, cnt = 0, flow = 0, cost = 0;
ll node[100007], edge[100007], nxt[100007], dist[100007], 
weight[100007], c[100007], mf[100007], pre[100007], visit[100007];
void addEdge(ll f, ll t, ll limit, ll w){
    nxt[cnt] = node[f];
    edge[cnt] = t;
    node[f] = cnt;
    weight[cnt] = w;
    c[cnt] = limit;
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
bool spfa(){
    memset(visit, 0, sizeof(visit));
    memset(mf, 0, sizeof(mf));
    memset(dist, 0x3f, sizeof(dist));
    queue<ll> que;
    que.push(st);
    dist[st] = 0, mf[st] = inf, visit[st] = 1;
    while (!que.empty()){
        int cur = que.front(); que.pop(); visit[cur] = 0;
        for (ll e = node[cur]; e >= 0; e = nxt[e]){
            ll t = edge[e], w = weight[e], limit = c[e];
            if (dist[t] > dist[cur] + w && limit){
                dist[t] = dist[cur] + w;
                mf[t] = min(mf[cur], limit);
                pre[t] = e;
                if (!visit[t]){
                    que.push(t);
                    visit[t] = 1;
                }
            }

        }
    }
    return mf[ed] > 0;
}
ll ek(){
    while (spfa()){
        int tmp = ed;
        while (tmp != st){
            ll e = pre[tmp];
            c[e] -= mf[ed];
            c[e^1] += mf[ed];
            tmp = edge[e^1];
        }
        flow += mf[ed];
        cost += mf[ed] * dist[ed];
    }
    return flow;
}

int main(){
    cin >> n >> m >> st >> ed;
    memset(node, -1, sizeof(node));
    for (int i = 0; i < m; i++){
        ll u, v, limit, w;
        cin >> u >> v >> limit >> w;
        addEdge(u, v, limit, w);
        addEdge(v, u, 0, -w);
    }
    ek();
    cout << flow << " " << cost << endl;
    return 0;
}