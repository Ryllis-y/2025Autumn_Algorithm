#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dis[307][307];  
ll node[307], edge[100007], weight[100007], nxt[100007];
ll n, m;
const ll INF = 0x3f3f3f3f3f3f3f3f;  
void addEdge(int i) {
    ll f, t, w;
    cin >> f >> t >> w;
    nxt[i] = node[f];
    node[f] = i;
    edge[i] = t;
    weight[i] = w;
    dis[f][t] = min(dis[f][t], w);
}

void floyd() {
    for (int k = 1; k <= n; k++)          
        for (int i = 1; i <= n; i++)      
            for (int j = 1; j <= n; j++)  
                if (dis[i][k] != INF && dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main() {
    cin >> n >> m;

    
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;

    memset(node, 0, sizeof(node));

    for (int i = 1; i <= m; i++) {
        addEdge(i);
    }

    floyd();

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (dis[u][v] == INF ? -1 : dis[u][v]) << endl;
    }

    return 0;
}