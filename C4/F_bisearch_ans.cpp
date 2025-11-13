#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//check
ll maxH(int s, int k) {
    priority_queue<int> pq;
    pq.push(s);
    ll totalH = 0;
    
    for (int i = 0; i < k; i++) {
        if (pq.top() < 2) {
            break; 
        }
        
        int q = pq.top();
        pq.pop();
        
        int a = q / 2;
        int b = q - a;
        totalH += (ll)a * b;
      
        pq.push(a);
        pq.push(b);
    }
    
    return totalH;
}

int main() {
    ll s, m;
    cin >> s >> m;
    if ((s / 2) * (s - s / 2) >= m) {
        cout << 1 << endl;
        return 0;
    }
    
    int left = 0, right = s - 1;
    int ans = -1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (maxH(s, mid) >= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}