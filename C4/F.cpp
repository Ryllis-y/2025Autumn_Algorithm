/*
Yuki 拥有 𝑆 枚硬币，最开始所有硬币都放在同一个存钱罐中。 现在 Yuki 打算将这些硬币放入若干个存钱罐中。

Yuki 每次会选择一个至少有 2 枚硬币的存钱罐，记这个存钱罐有 𝑄 枚硬币，Yuki 可以从中任意拿出 𝑎 枚硬币放入一个新的存钱罐中，其中 𝑎 需要满足 1≤𝑎≤𝑄−1，此后 Yuki 获得 𝑎⋅(𝑄−𝑎) 的快乐值。

现在 Yuki 希望获得至少 𝑀 点快乐值，请帮 Yuki 求出她最少需要准备多少个新的存钱罐（即最少要执行多少次上述移动硬币的操作）。

输入格式

输入仅包含一行。
第一行两个正整数 𝑆（2≤𝑆≤1000），𝑀（1≤𝑀≤109）。

输出格式

输出一个非负整数表示答案；如果 Yuki 无论如何都不能获得 𝑀 点快乐值，输出 −1 。
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int s, m;
    cin >> s >> m;
    if (m == 0){
        cout << 0;
        
    } 
    priority_queue<int> pq;
    pq.push(s);
    ll total = 0;
    ll cnt = 0;
    
    while (true) {
        ll q = pq.top();
        pq.pop();
        if (q < 2) break; 
        
        ll a = q / 2;
        ll b = q - a;
        ll gain = a * b;
        total += gain;
        cnt++;
        
        if (total >= m) {
            cout << cnt << endl;
            return 0;
        }
        
        pq.push(a);
        pq.push(b);
    }
    
    cout << -1 << endl;
    return 0;
}