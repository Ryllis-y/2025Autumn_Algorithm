#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
int parent[MAXN];
int n, m;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    for (int i = 1; i < MAXN; i++) {
        parent[i] = i;
    }
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);  
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}

