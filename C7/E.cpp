#include <bits/stdc++.h>
using namespace std;
int weight[200007], head[400007], to[400007], nxt[400007];
int idx = 1;
int visit[200007];
void addEdge(){
    int u, v;
    cin >> u >> v;
    nxt[idx] = head[u];
    to[idx] = v;
    head[u] = idx++;
    nxt[idx] = head[v];
    to[idx] = u;
    head[v] = idx++;
}
int dfs(int pos, int& mask){
    int ans = 1;
    visit[pos] = 1;
    mask |= (1 << (weight[pos] - 1));
    for (int e = head[pos]; e; e = nxt[e]){
        int t = to[e];
        
        if (visit[t]) continue;
        
        ans += dfs(t, mask);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> weight[i];
    }
    for (int i = 1; i <= m; i++){
        addEdge();
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visit[i]){
            int mask = (1 << (weight[i] - 1));
            int tmp = dfs(i, mask);
            if (mask == (1 << 9) - 1){
                cnt += tmp;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}