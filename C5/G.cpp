#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int a, p;
}Node;
Node toby[1007], mogy[1007];
int main() {
    int n;
    cin >> n;
  
    for (int i = 0; i < n; i++) cin >> toby[i].a;
    for (int i = 0; i < n; i++) cin >> toby[i].p;
    for (int i = 0; i < n; i++) cin >> mogy[i].a;
    for (int i = 0; i < n; i++) cin >> mogy[i].p;

    sort(toby, toby + n, [](const Node& x, const Node& y) {
        return x.a > y.a;
    });

    sort(mogy, mogy + n, [](const Node& x, const Node& y) {
        return x.a > y.a;
    });
    
    multiset<int> mp; 
    int ans = 0;
    int j = 0; 
    
    for (int i = 0; i < n; i++) {
        while (j < n && mogy[j].a >= toby[i].p) {
            mp.insert(mogy[j].p);
            j++;
        }
        auto it = mp.lower_bound(toby[i].a + 1);
        if (it != mp.begin()) {
            it--;
            mp.erase(it);
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
