#include <bits/stdc++.h>
using namespace std;
int fa[200007], weight[200007], visit[200007], size[200007], mask[200007];

int find(int cur){
    if (fa[cur] == cur) return cur;
    fa[cur] = find(fa[cur]);
    return fa[cur];
}

int merge(int a, int b){
    int pa = find(a), pb = find(b);
    if (pa != pb){
        fa[pb] = pa;
        size[pa] += size[pb];
        mask[pa] |= mask[pb];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> weight[i];
        fa[i] = i;
        size[i] = 1;
        mask[i] = 1 << (weight[i] - 1);
    }
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (fa[i] == i){
            if (mask[i] == (1 << 9) - 1)
                ans += size[i];
        }
    }
    cout << ans << endl;
    return 0;
    
}