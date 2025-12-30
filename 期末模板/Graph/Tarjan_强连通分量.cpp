#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
int node[maxn], edge[maxn], nxt[maxn], cnt = 1;
int dfn[maxn], low[maxn], scc[maxn], scccnt = 0, idx = 0;
stack<int> stk;
bool instk[maxn];

void addEdge(int f, int t){
    nxt[cnt] = node[f];
    node[f] = cnt;
    edge[cnt] = t;
    cnt++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++idx;
    stk.push(u);
    instk[u] = true;
    for (int e = node[u]; e; e = nxt[e]){
        int v = edge[e];
        if (!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instk[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]){
        scccnt++;
        int v;
        do {
            v = stk.top();
            stk.pop();
            instk[v] = false;
            scc[v] = scccnt;
        } while (v != u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++){
        if (!dfn[i]){
            tarjan(i);
        }
    }
    cout << scccnt << endl;
    return 0;
}


