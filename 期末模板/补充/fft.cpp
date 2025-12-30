#include <bits/stdc++.h>
using namespace std;

// 1. 紧凑版复数类
struct Complex {
    double x, y;
    Complex(double x=0, double y=0):x(x),y(y){}
    Complex operator+(const Complex& b) const { return {x+b.x, y+b.y}; }
    Complex operator-(const Complex& b) const { return {x-b.x, y-b.y}; }
    Complex operator*(const Complex& b) const { return {x*b.x-y*b.y, x*b.y+y*b.x}; }
};

// 2. FFT 核心
void fft(vector<Complex>& a, int inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * M_PI / len * inv;
        Complex wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v, a[i+j+len/2] = u - v, w = w * wlen;
            }
        }
    }
    if (inv == -1) for (auto& x : a) x.x /= n;
}

// 3. 多项式类封装
struct Poly : vector<long long> {
    using vector<long long>::vector; // 继承构造函数

    // 加法重载: a = a + b
    Poly operator+(const Poly& b) const {
        Poly res = *this;
        if (res.size() < b.size()) res.resize(b.size());
        for (int i = 0; i < b.size(); i++) res[i] += b[i];
        return res;
    }
    void operator+=(const Poly& b) { *this = *this + b; }

    // 乘法重载 (FFT): a = a * b
    Poly operator*(const Poly& b) const {
        int n = size(), m = b.size();
        int L = 1; while (L < n + m) L <<= 1;
        vector<Complex> fa(L), fb(L);
        for (int i = 0; i < n; i++) fa[i].x = (*this)[i];
        for (int i = 0; i < m; i++) fb[i].x = b[i];
        
        fft(fa, 1); fft(fb, 1);
        for (int i = 0; i < L; i++) fa[i] = fa[i] * fb[i];
        fft(fa, -1);

        Poly res(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) res[i] = round(fa[i].x);
        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Poly A(n + 1), B(m + 1);
    for (int i = 0; i <= n; i++) cin >> A[i];
    for (int i = 0; i <= m; i++) cin >> B[i];

    // 像基本类型一样使用
    Poly C = A * B;
    Poly D = A + A; // 示例加法
    
    for (long long x : C) cout << x << " ";
    return 0;
}