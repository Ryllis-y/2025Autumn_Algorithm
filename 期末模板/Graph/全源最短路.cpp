/*
给定一个包含 n 个结点和 m 条带权边的有向图，求所有点对间的最短路径长度，一条路径的长度定义为这条路径上所有边的权值和。

注意：

边权可能为负，且图中可能存在重边和自环；

部分数据卡 n 轮 SPFA 算法。

输入格式
第 1 行：2 个整数 n,m，表示给定有向图的结点数量和有向边数量。

接下来 m 行：每行 3 个整数 u,v,w，表示有一条权值为 w 的有向边从编号为 u 的结点连向编号为 v 的结点。

输出格式
若图中存在负环，输出仅一行 −1。

若图中不存在负环：

输出 n 行：令 dis 
i,j
​	
  为从 i 到 j 的最短路，在第 i 行输出  
j=1
∑
n
​	
 j×dis 
i,j
​	
 ，注意这个结果可能超过 int 存储范围。

如果不存在从 i 到 j 的路径，则 dis 
i,j
​	
 =10 
9
 ；如果 i=j，则 dis 
i,j
​	
 =0。
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
int n, m;
ll node[10007], edge[10007], nxt[10007], weight[10007], nw[10007];
ll ecnt = 1, tcnt;
queue<ll> que;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
ll visit[10007], dist1[10007], dist2[10007], cntc[10007];
void addEdge(ll f, ll t, ll w){
    nxt[ecnt] = node[f];
    weight[ecnt] = w;
    node[f] = ecnt;
    edge[ecnt] = t;
    ecnt++;
}
bool spfa(){
    que.push(0);
    memset(dist1, 0x3f, sizeof(dist1));
    memset(cntc, 0, sizeof(cntc));
    dist1[0] = 0;
    while (!que.empty()){
        int cur = que.front();
        que.pop(), visit[cur] = 0;
        for (ll e = node[cur]; e; e = nxt[e]){
            ll t = edge[e], w = weight[e];
            if (dist1[t] > dist1[cur] + w){
                dist1[t] = dist1[cur] + w;
                if (!visit[t]){
                    cntc[t] = cntc[cur] + 1;
                    que.push(t);
                    visit[t] = 1;
                    if (cntc[t] >= n + 1) return true;
                }
            }
        }
    }
    return false;
}
void processNw(){
    for (int i = 0; i <= n; i++){
        for (int e = node[i]; e; e = nxt[e]){
            ll t = edge[e];
            nw[e] = weight[e] + dist1[i] - dist1[t]; 
        }
    }
}
void dij(ll st){
    memset(dist2, 0x3f, sizeof(dist2));
    memset(visit, 0, sizeof(visit));
    while (!pq.empty()) pq.pop();
    dist2[st] = 0;
    pq.push({0, st});
    while (!pq.empty()){
        auto [d, cur] = pq.top();
        pq.pop();
        if (visit[cur]) continue;
        visit[cur] = 1;
        for (ll e = node[cur]; e; e = nxt[e]){
            ll t = edge[e], w = nw[e];
            if (dist2[t] > dist2[cur] + w){
                dist2[t] = dist2[cur] + w;
                pq.push({dist2[t], t});
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dist2[i] == 0x3f3f3f3f3f3f3f3fLL) { 
            sum += (ll)i * inf;
        } else {
            ll actual_dist = dist2[i] - dist1[st] + dist1[i];
            sum += (ll)i * actual_dist;
        }
    }
    cout << sum << endl;
    return ;
}
int main(){
    memset(node, 0, sizeof(node));
    memset(nxt, 0, sizeof(nxt));
    memset(edge, 0, sizeof(edge));
    memset(weight, 0, sizeof(weight));
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int f, t, w;
        cin >> f >> t >> w;
        addEdge(f, t, w);
    }
    tcnt = ecnt;
    for (int i = 1; i <= n; i++){
        addEdge(0, i, 0);
    }
    if (spfa()) {
        cout << -1 << endl;
        return 0;
    }
    processNw();
    for (int i = 1; i <= n; i++){
        dij(i);
    }
    return 0;


}