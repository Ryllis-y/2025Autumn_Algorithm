#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100007;
ll tree[maxn];
int n;

int lowbit(int x){
    return x & -x;
}

void add(int x, ll val){
    while (x <= n){
        tree[x] += val;
        x += lowbit(x);
    }
}

ll query(int x){
    ll sum = 0;
    while (x > 0){
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        ll val;
        cin >> val;
        add(i, val);
    }
    while (m--){
        int op, l, r;
        ll val;
        cin >> op;
        if (op == 1){
            cin >> l >> val;
            add(l, val);
        }
        else {
            cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
        }
    }
    return 0;
}


