#include <bits/stdc++.h>
using namespace std;
#define N 5000005

int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % mod;
}

int a[N] = {1,1,2,3,3,3,4};
int n = 7;

long long calculateF() {
    // 复制数组（0到n-1共n个元素）
    vector<int> sorted(a, a + n - 1);  // 直接从a[0]开始复制n个元素
    sort(sorted.begin(), sorted.end());
    
    // 记录每个元素首次出现的顺序（逻辑上从1开始）
    unordered_map<int, int> ord;
    int k = 1;
    for (int x : sorted) {
        if (!ord.count(x)) {
            ord[x] = k++;
        }
    }
    
    // 计算f(A)：遍历原数组所有元素（0到n-1）
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += 1LL * ord[a[i]] * a[i];
    }
    return res;
}

int main(){
    cout << calculateF() << endl;
    return 0;
}