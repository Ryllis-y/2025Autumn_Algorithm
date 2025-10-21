#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll> l;  //大根堆，下面小根堆
priority_queue<ll, vector<ll>, greater<ll>> r;
ll sl, sr, sb;   //b的总和单独存储 分析可知x的取值就在中点 所以维护左右两边的坐标总和
//左侧部分绝对值直接减掉总和，右侧减掉总和再取相反数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            ll a, b;
            cin >> a >> b;
            sb += b;
            
            if (l.empty() || a <= l.top()) {
                l.push(a);
                sl += a;
            } else {
                r.push(a);
                sr += a;
            }
            
            // 干什么。
            if (l.size() > r.size() + 1) {
                ll t = l.top();
                l.pop();
                sl -= t;
                r.push(t);
                sr += t;
            } else if (r.size() > l.size()) {
                ll t = r.top();
                r.pop();
                sr -= t;
                l.push(t);
                sl += t;
            }
        } 
        else {
            ll mid = l.top();
            ll ls = l.size(), rs = r.size();
            ll ans = mid * ls - sl + sr - mid * rs + sb;
            cout << mid << " " << ans << "\n";
        }
    }
    
    return 0;
}