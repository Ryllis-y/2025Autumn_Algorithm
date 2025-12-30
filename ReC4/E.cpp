#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int head[100007], to[100007], nxt[100007], weight[100007], indegree[100007];
int visit[100007];
ll dist[100007];
int n, m;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector<int> ans;
void addEdge(int i){
    int u, v, w;
    cin >> u >> v >> w;
    nxt[i] = head[u];
    to[i] = v;
    weight[i] = w;
    head[u] = i;
    indegree[v]++;
}
void topo(){
    queue<int> que;
    for (int i = 1; i <= n; i++){
        if (indegree[i] == 0) que.push(i);
    }
    while (!que.empty()){
        int cur = que.front();
        que.pop();
        if (visit[cur]) continue;
        visit[cur] = 1;
        ans.push_back(cur);
        for (int e = head[cur]; e; e = nxt[e]){
            int t = to[e];
            if (--indegree[t] == 0) que.push(t);
        }
    }
}

void road(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (auto x : ans){
        if (dist[x] == inf) continue;
        for (int e = head[x]; e; e = nxt[e]){
            int t = to[e], w = weight[e];
            dist[t] = min(dist[t], dist[x] + w);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        addEdge(i);
    }
    topo();
    for (auto x : ans){
        cout << x << " ";
    }
    cout << endl;
    road();
    for (int i = 1; i <= n; i++){
        cout << (dist[i] == inf ? -1 : dist[i]) << " ";
    }
    cout << endl;
    return 0;
}