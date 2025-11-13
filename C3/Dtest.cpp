#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        
        int pre2 = 0, pre1 = 0, current = 0;
        
        for (int i = 1; i <= n; i++){
            int num;
            cin >> num;
            current = max(pre1, pre2 + num);
            pre2 = pre1;
            pre1 = current;
        }
        
        cout << current << endl;
    }
    return 0;
}