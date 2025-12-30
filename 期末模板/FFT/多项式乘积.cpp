#include <bits/stdc++.h>
using namespace std;
//using Complex = complex<double>;

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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string xx, yy;
    while (t--){
        cin >> xx >> yy;
        int al = xx.length(), bl = yy.length();
        int n = 1;
        while (n < al + bl + 2) n <<= 1;
        vector<Complex> fa(n), fb(n);
        for (int i = 0; i < al; i++) {
            fa[i] = Complex(xx[al - 1 - i] - '0', 0);
        }
        for (int i = 0; i < bl; i++) {
            fb[i] = Complex(yy[bl - 1 - i] - '0', 0);
        }
        fft(fa, false), fft(fb, false);
        vector<int> result(n);
        for (int i = 0; i < n; i++) fa[i] *= fb[i];
        fft(fa, true);
        for (int i = 0; i < n; i++) {
            result[i] = round(fa[i].x);
        }





        
        for (int i = 0; i < n - 1; i++) {
            result[i + 1] += result[i] / 10; 
            result[i] %= 10;         
        }

        int pos = n - 1;
        while (pos > 0 && result[pos] == 0) pos--;

        for (; pos >= 0; pos--) {
            cout << result[pos];
        }
        cout << endl;
    }
    return 0;
}