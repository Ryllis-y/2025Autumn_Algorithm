//本题思路经ai指导
//若 b_i ⊕ b_{i+1} = a_i，则 b_{i+1} = b_i ⊕ a_i

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i];
    }

    vector<int> s(n, 0);
    for (int i = 1; i < n; ++i) {
        s[i] = s[i-1] ^ a[i-1];
    }

    vector<int> b;
    for (int x = 0; x < n; ++x) { // 枚举 b1
        vector<int> temp(n);
        bool valid = true;
        vector<bool> used(n, false); 
        for (int k = 0; k < n; ++k) {
            temp[k] = x ^ s[k];
            if (temp[k] < 0 || temp[k] >= n || used[temp[k]]) {
                valid = false;
                break;
            }
            used[temp[k]] = true;
        }
        if (valid) {
            b = temp;
            break;
        }
    }
    for (int num : b) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}