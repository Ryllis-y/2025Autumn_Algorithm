//本题思路经ai指导
//若 b_i ⊕ b_{i+1} = a_i，则 b_{i+1} = b_i ⊕ a_i

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    vector<int> s(n, 0);
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] ^ a[i - 1];
    }

    //0到n-1的异或和
    int total_xor = 0;
    for (int i = 0; i < n; ++i) {
        total_xor ^= i;
    }

    int s_total = 0;
    for (int val : s) {
        s_total ^= val;
    }

    int b1;
    if (n % 2 == 1) {
        b1 = total_xor ^ s_total;
    } else {
        // 对于偶数 n，通过验证找到合法的 b1
        // 从 0 开始枚举，直到生成的序列所有元素都在 [0, n-1] 范围内
        for (b1 = 0; ; ++b1) {
            bool valid = true;
            for (int k = 0; k < n; ++k) {
                int val = b1 ^ s[k];
                if (val < 0 || val >= n) {
                    valid = false;
                    break;
                }
            }
            if (valid) break;
        }
    }

    vector<int> b(n);
    for (int k = 0; k < n; ++k) {
        b[k] = b1 ^ s[k];
    }

    for (int num : b) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}