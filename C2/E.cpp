#include <bits/stdc++.h>
using namespace std;

#define N 5000005
#define MOD 100003

int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % MOD;
}

int a[N];
int cnt[MOD + 5];
long long pre[MOD + 5]; 

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
    
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            a[i] = nextRand();
            cnt[a[i]]++;
        }
        
       
        pre[0] = 0;
        for (int v = 1; v < MOD; v++) {
            pre[v] = pre[v - 1] + cnt[v - 1];
        }

        long long sum_a = 0;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            sum_a += a[i];
            int order = 1 + pre[a[i]];
            res += (long long)order * a[i];
        }
        
        printf("%lld\n", res);
    }
    return 0;
}