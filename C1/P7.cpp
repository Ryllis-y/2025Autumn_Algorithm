#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 树状数组
struct FenwickTree {
    vector<int> tree;
    int size;

    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0); // 1-based索引
    }

    void update(int x) {
        for (; x <= size; x += x & -x) {
            tree[x]++;
        }
    }

    // 前缀查询：查询[1, x]的总和（即比x小的元素个数）
    int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res += tree[x];
        }
        return res;
    }
};

// 计算排列的逆序对数
int countInversions(const vector<int>& p) {
    int n = p.size();
    FenwickTree ft(n);
    int cnt = 0;

    // 从后往前遍历，统计每个元素右侧比它小的元素个数
    for (int i = n - 1; i >= 0; --i) {
        // p[i]右侧比它小的元素个数 = 已插入树状数组的元素中 ≤ p[i]-1 的个数
        cnt += ft.query(p[i] - 1);
        ft.update(p[i]); // 将当前元素插入树状数组
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        int inv_cnt = countInversions(p);
        cout << (inv_cnt % 2 == 0 ? "Alice" : "Bob") << '\n';
    }
    cout << endl;


    return 0;
}