#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> fre;
    for (char c : s) {
        fre[c]++;
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (auto p : fre) {
        pq.push(p.second);
    }

    ll total = 0;
    while (pq.size() > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ll sum = a + b;
        total += sum;
        pq.push(sum);
    }

    cout << total << endl;
    return 0;
}