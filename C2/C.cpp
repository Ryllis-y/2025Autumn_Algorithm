#include <stdio.h>
#define N 200005

int a[N], n, q;

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

void down(int *h, int pos, int sz) {
    while (pos * 2 <= sz) {
        int c = pos * 2;
        if (c + 1 <= sz && h[c + 1] > h[c]) c++;
        if (h[c] > h[pos]) {
            swap(&h[c], &h[pos]);
            pos = c;
        } else break;
    }
}

void build(int *h, int sz) {
    for (int i = sz / 2; i >= 1; i--) down(h, i, sz);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    int b[N];
    for (int i = 1; i <= n; i++) b[i] = a[i];
    int sz = n;
    build(b, sz);
    for (int i = 0; i < q; i++) {
        swap(&b[1], &b[sz]);
        sz--;
        down(b, 1, sz);
    }
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    puts("");

    sz = n;
    build(a, sz);
    for (int i = 0; i < n; i++) {
        swap(&a[1], &a[sz]);
        sz--;
        down(a, 1, sz);
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    
    return 0;
}
    