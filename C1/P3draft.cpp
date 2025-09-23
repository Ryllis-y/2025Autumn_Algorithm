#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    int minT = 1e9 + 10; 
    int maxT = 0;         
    
    for (int i = 0; i < m; ++i) {
        int x;
        char d;
        cin >> x >> d;
        
        int t;
        if (d == 'L') {
            t = x; 
        } else {
            t = (n + 1) - x; 
        }
        
        minT = min(minT, t);
        maxT = max(maxT, t);
    }
    
    cout << minT << " " << maxT << endl;
    return 0;
}