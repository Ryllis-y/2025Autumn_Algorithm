#include <bits/stdc++.h>
using namespace std;
//using Complex = complex<double>;
#define int long long
const int offset = 50002;
struct Complex {
    double x, y; // 实部 x, 虚部 y

    Complex(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Complex operator + (const Complex& b) const {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator - (const Complex& b) const {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator * (const Complex& b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
    Complex& operator += (const Complex& b) {
        x += b.x;
        y += b.y;
        return *this;
    }
    Complex& operator *= (const Complex& b) {
        double tmp_x = x * b.x - y * b.y;
        y = x * b.y + y * b.x;
        x = tmp_x;
        return *this;
    }
};
const double PI = acos(-1.0);
void fft(vector<Complex>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        Complex wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i + j];
                Complex v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (int i = 0; i < n; i++) a[i].x /= n; 
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int size = 1;
        while (size < 200007 + 1) size <<= 1;
        vector<int> a(size, 0), tmp(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> tmp[i];
        
        vector<Complex> fa(size);
        for (int i = 0; i < n; i++) a[tmp[i] + offset] = 1;
        for (int i = 0; i < size; i++){
            fa[i] = Complex(a[i], 0); 
        }
        fft(fa, false);
        for (int i = 0; i < size; i++){
            fa[i] *= fa[i];
        }
        fft(fa, true);
        unordered_map<int,int> mp;
        int cnt = 0;
        for (int i = 0; i < size; i++){
            int val = (int)(fa[i].x + 0.5);
            if (val > 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}