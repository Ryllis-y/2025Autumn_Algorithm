#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        ll prev2 = 0, prev1 = 0;  
        ll x;
        
        for (int i = 0; i < n; ++i) {
            cin >> x;  
            
            if (i == 0) {
                prev1 = max(0LL, x);  
            } else if (i == 1) {
                prev2 = prev1;  
                prev1 = max(0LL, max(prev1, x));  
            } else {
                long long curr = max(prev1, prev2 + x);  
                prev2 = prev1;
                prev1 = curr;
            }
        }
        
        cout << prev1 << '\n';  
    }
    return 0;
}