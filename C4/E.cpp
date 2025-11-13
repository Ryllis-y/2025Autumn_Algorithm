#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
int n, m;
int node[100007], edge[100007], nxt[100007], weight[100007], indegree[100007], visit[100007], cop[100007], dis[100007];
queue<int> que;
vector<int> ans;
void addEdge(int i){
    int u, v, w;
    cin >> u >> v >> w;
    nxt[i] = node[u];
    edge[i] = v;
    node[u] = i;
    weight[i] = w;
    indegree[v]++;
}
void topo(){
    for (int i = 1; i <= n; i++){
        if (indegree[i] == 0){
            que.push(i);
        }
    }
    while (!que.empty()){
        int cur = que.front();
        que.pop();
        if (visit[cur]) continue;
        ans.push_back(cur);
        visit[cur] = 1;
        for (int e = node[cur]; e; e = nxt[e]){
            int t = edge[e];
            indegree[t]--;
            if (indegree[t] == 0){
                que.push(t);
            }
        }
    }
    for (int index : ans){
        cout << index << " ";
    }
    cout << endl;
    return ;
    
}

void dist() {
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dis[1] = 0;
    for (int u : ans) {
        if (dis[u] == INF) continue;  
        for (int e = node[u]; e; e = nxt[e]) {
            int v = edge[e];  
            int w = weight[e];  
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "-1 ";  
        } else {
            cout << dis[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        addEdge(i);
    }
    memcpy(cop, indegree, sizeof(indegree));
    topo();
    dist();
    return 0;
}