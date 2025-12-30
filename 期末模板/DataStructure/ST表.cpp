#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
int st[maxn][20], arr[maxn], lg[maxn];
int n, m;

void init(){
    lg[1] = 0;
    for (int i = 2; i <= n; i++){
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++){
        st[i][0] = arr[i];
    }
    for (int j = 1; j <= lg[n]; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    init();
    while (m--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}


