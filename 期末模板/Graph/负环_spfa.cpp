#include <bits/stdc++.h>
using namespace std;

int node[3007], edge[6007], nxt[6007], weight[6007], dist[3007];
queue<int> que;
int visit[3007], cnt[3007];
int n, m, c = 1;
void addEdge(int i){
    int f, t, w;
    cin >> f >> t >> w;
    nxt[c] = node[f];
    node[f] = c;
    edge[c] = t;
    weight[c] = w;
    c++;
    if (w >= 0){
        nxt[c] = node[t];
        node[t] = c;
        edge[c] = f;
        weight[c] = w;
        c++;
    }
}
bool spfa(){
    que.push(1), dist[1] = 0;
    while (!que.empty()){
        int cur = que.front();
        visit[cur] = 0, que.pop();
        for (int e = node[cur]; e; e = nxt[e]){
            int t = edge[e];
            if (dist[t] > dist[cur] + weight[e]){
                dist[t] = dist[cur] + weight[e];
                if (!visit[t]) {
                    cnt[t] = cnt[cur] + 1;
                    que.push(t), visit[t] = 1;
                    if (cnt[t] >= n) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        c = 1;
        memset(nxt, 0, sizeof(nxt));
        memset(node, 0, sizeof(node));
        memset(edge, 0, sizeof(edge));
        memset(dist, 0x3f, sizeof(dist));
        memset(cnt, 0, sizeof(cnt));
        memset(visit, 0, sizeof(visit));
        while (!que.empty()) que.pop();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            addEdge(i);
        }
        if (spfa()){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}