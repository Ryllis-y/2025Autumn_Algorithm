#include <bits/stdc++.h>
using namespace std;

const int MAXN = 807;     
const int MAXM = 640007;   
const int INF = 0x3f3f3f3f;

int n, cnt;
int a[MAXN], p[MAXN];
int node[MAXN], level[MAXN], cur[MAXN];
int edge[MAXM], cap[MAXM], nxt[MAXM];

void addEdge(int u, int v, int c) {
    edge[cnt] = v;
    cap[cnt] = c;
    nxt[cnt] = node[u];
    node[u] = cnt++;
    edge[cnt] = u;
    cap[cnt] = 0;
    nxt[cnt] = node[v];
    node[v] = cnt++;
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int& i = node[u]; i != -1; i = nxt[i]) {
            int v = edge[i];
            if (level[v] == -1 && cap[i] > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    int sum = 0;  // 多路增广的总流量
    
    // 使用当前弧优化：cur[u] 会被修改
    for (int &i = cur[u]; i != -1; i = nxt[i]) {
        int v = edge[i];
        // 优化：分层限制搜索深度
        if (level[v] == level[u] + 1 && cap[i] > 0) {
            int f = dfs(v, t, min(flow, cap[i]));
            if (f > 0) {
                cap[i] -= f;
                cap[i ^ 1] += f;
                sum += f;       // 累加已增广的流量
                flow -= f;      // 减少剩余可用流量
                
                // 优化：剩余流量优化（mf==0提前退出）
                if (flow == 0) break;
            }
        }
    }
    // 优化：残枝优化（如果当前点没流出任何流量，标记为无效）
    if (sum == 0) level[u] = -1;
    return sum;
}

int dinic(int s, int t) {
    int mf = 0;
    while (bfs(s, t)) {
        memcpy(cur, node, sizeof(node));
        while (int f = dfs(s, t, INF)) {
            mf += f;
        }
    }
    return mf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(node, -1, sizeof(node));
    cnt = 0; 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = n + 1; i <= 2 * n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) cin >> p[i];
    int s = 0;          
    int t = 2 * n + 1;  
    for (int i = 1; i <= n; i++) {
        addEdge(s, i, 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            if (a[i] >= p[j] && a[j] >= p[i])
                addEdge(i, j, 1);
        }
    }
    for (int j = n + 1; j <= 2 * n; j++) {
        addEdge(j, t, 1);
    }
    int ans = dinic(s, t);
    cout << ans << endl;
    return 0;
}