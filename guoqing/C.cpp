#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 10007;
int m, n;
int a[100007], b[100007];
int compute(int* arr, int x, int cnt){
    int ans = 0;
    for (int i = cnt; i >= 0; i--){
        ans = ((ans * x % MOD) + arr[i]) % MOD;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    cin >> n;
    for (int i = 0; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i <= m; i++){
        cin >> b[i];
    }
    //cout << compute(a, 2, n) << endl;
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> x >> y;
        cout << compute(a, x, n) * compute(b, y, m) %MOD << endl;
    }
    return 0;

}