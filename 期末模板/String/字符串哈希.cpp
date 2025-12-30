#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1000007;
const ull base = 131;
ull h[maxn], p[maxn];
char s[maxn];

void init(){
    p[0] = 1;
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++){
        h[i] = h[i - 1] * base + s[i];
        p[i] = p[i - 1] * base;
    }
}

ull getHash(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> (s + 1);
    init();
    int m;
    cin >> m;
    while (m--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (getHash(l1, r1) == getHash(l2, r2)){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}


