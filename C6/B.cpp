#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <iomanip>

using namespace std;


using Complex = complex<double>;
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
        for (Complex& x : a)
            x /= n;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (cin >> n) {
        int size = 1 << n; 
        vector<Complex> coeffs(size);

        for (int i = 0; i < size; i++) {
            double c;
            cin >> c;
            coeffs[i] = Complex(c, 0);
        }


        fft(coeffs, false);

        Complex z(0, 0);
        
        for (int k = 0; k < size; k++) {
            
            z += coeffs[k] * cos((double)k);
        }

        cout << fixed << setprecision(2) << z.real() << " " << z.imag() << endl;
    }

    return 0;
}