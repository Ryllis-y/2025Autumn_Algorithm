#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mp[207][207], dist[207][207];
const ll INF = 0x3f3f3f3f;
int main(){
    int n, m;
    cin >> n >> m;
    memset(mp, 0x3f, sizeof(mp));
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; i++){
        dist[i][i] = mp[i][i] = 0;
    }
    ll u, v, w;
    for (int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        dist[u][v]=min(dist[u][v],w);
		dist[v][u]=min(dist[v][u],w);
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
    }
    ll ans = 0x3f3f3f3f;
    for (int k = 1; k <= n; k++){
        for (int i = 1; i < k; i++){
            for (int j = i + 1; j < k; j++){
                if (dist[i][j] < INF && mp[i][k] < INF && mp[k][j] < INF) 
                    ans = min(ans, mp[i][k] + mp[k][j] + dist[i][j]);
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }
    if(ans == 0x3f3f3f3f) cout << "No solution." << endl;
    else
        cout << ans << endl;
    return 0;
}