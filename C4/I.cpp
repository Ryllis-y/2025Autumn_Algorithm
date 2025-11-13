#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct Item {
    int w, v;
} items[5005];

ll f[10007];  
ll g[10007];  
ll prefix[5005];

bool cmp(const Item& a, const Item& b) {
    return a.v > b.v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, W, k;
        cin >> n >> W >> k;
        for (int i = 0; i < n; i++) {
            cin >> items[i].w >> items[i].v;
        }

        sort(items, items + n, cmp);

        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + items[i - 1].v;
        }

        for (int j = 0; j <= W; j++) {
            f[j] = 0;
        }
        ll ans = 0;
        // 01 倒序处理
        for (int i = n; i >= 0; i--) {
            if (i <= k) {
                ans = max(ans, prefix[i] + f[W]);
            }
            if (i == 0) break;
            
            for (int j = 0; j <= W; j++) {
                g[j] = f[j];
                if (j >= items[i - 1].w) {
                    g[j] = max(g[j], f[j - items[i - 1].w] + items[i - 1].v);
                }
            }
            // 复制回f
            for (int j = 0; j <= W; j++) {
                f[j] = g[j];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}