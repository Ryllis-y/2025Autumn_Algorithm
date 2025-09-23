#include <stdio.h>
#include <stdlib.h>

// 多项式相加核心函数：双指针合并
void addPolynomial(
    long long *a, long long *A, int n,
    long long *b, long long *B, int m,
    long long **c_out, long long **C_out, int *k_out
) {
   
    long long *c = (long long *)malloc((n + m) * sizeof(long long));
    long long *C = (long long *)malloc((n + m) * sizeof(long long));
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            // 第一个多项式的项指数更小，直接加入
            c[k] = a[i];
            C[k] = A[i];
            i++;
            k++;
        } else if (A[i] > B[j]) {
            // 第二个多项式的项指数更小，直接加入
            c[k] = b[j];
            C[k] = B[j];
            j++;
            k++;
        } else {
            // 同类项，系数相加（题目保证和不为0）
            c[k] = a[i] + b[j];
            C[k] = A[i]; 
            i++;
            j++;
            k++;
        }
    }

    // 处理第一个多项式的剩余项
    while (i < n) {
        c[k] = a[i];
        C[k] = A[i];
        i++;
        k++;
    }

    // 处理第二个多项式的剩余项
    while (j < m) {
        c[k] = b[j];
        C[k] = B[j];
        j++;
        k++;
    }

    *c_out = c;
    *C_out = C;
    *k_out = k;
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int n;
        scanf("%d", &n);
        long long *a = (long long *)malloc(n * sizeof(long long));
        long long *A = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        for (int i = 0; i < n; i++) scanf("%lld", &A[i]);

        int m;
        scanf("%d", &m);
        long long *b = (long long *)malloc(m * sizeof(long long));
        long long *B = (long long *)malloc(m * sizeof(long long));
        for (int i = 0; i < m; i++) scanf("%lld", &b[i]);
        for (int i = 0; i < m; i++) scanf("%lld", &B[i]);

        long long *c, *C;
        int k;
        addPolynomial(a, A, n, b, B, m, &c, &C, &k);

        printf("%d\n", k);
        for (int i = 0; i < k; i++) {
            printf("%lld%c", c[i], i == k-1 ? '\n' : ' ');
        }
        for (int i = 0; i < k; i++) {
            printf("%lld%c", C[i], i == k-1 ? '\n' : ' ');
        }

        free(a);
        free(A);
        free(b);
        free(B);
        free(c);
        free(C);
    }

    return 0;
}