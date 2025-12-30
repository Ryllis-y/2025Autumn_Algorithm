#include <bits/stdc++.h>
using namespace std;
#define int long long
int node[200007], edge[200007], weight[200007], nxt[200007], dist[200007], visit[200007];
const int inf = 0x3f3f3f3f;
void addEdge(int i){
    int f, t, w;
    cin >> f >> t >> w;
    weight[i] = w;
    nxt[i] = node[f];
    edge[i] = t;
    node[f] = i;
}
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
signed main(){
    int n, m, s;
    cin >> n >> m >> s;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= m; i++){
        addEdge(i);
    }
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        auto [d, cur] = pq.top();
        pq.pop();
        if (visit[cur]){
            continue;
        }
        visit[cur] = 1;
        for (int e = node[cur]; e; e = nxt[e]){
            int t = edge[e];
            if (dist[t] > dist[cur] + weight[e]){
                dist[t] = dist[cur] + weight[e];
                pq.push({dist[t], t});
            }

        }
        
    }

    for (int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}