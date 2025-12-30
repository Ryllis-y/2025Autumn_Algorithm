#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2007;
const int mod = 1e9 + 7;
ll C[maxn][maxn];

void init(){
    for (int i = 0; i < maxn; i++){
        C[i][0] = 1;
        for (int j = 1; j <= i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    while (n--){
        int a, b;
        cin >> a >> b;
        cout << C[a][b] << endl;
    }
    return 0;
}


