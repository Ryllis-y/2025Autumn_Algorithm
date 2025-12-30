#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;  // d, pos

const ll INF = 1e18;
const int MAXN = 1e5 + 5;
const int MAXM = 5e5 + 5;

vector<pii> graph[MAXN];
ll dist1[MAXN], distN[MAXN];
bool visited[MAXN];
int n, m, k;
vector<int> special;

void dijkstra(int start, ll dist[]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto &[v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }
    
    special.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> special[i];
    }
    
    dijkstra(1, dist1);
    dijkstra(n, distN);
    
    ll ans = INF;
    for (int s : special) {
        if (dist1[s] < INF && distN[s] < INF) {
            ans = min(ans, dist1[s] + distN[s]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}