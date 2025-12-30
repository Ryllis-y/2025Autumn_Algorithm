#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;

double f(double x){
    return x * x * x - 3 * x * x - 3 * x - 1;
}

double ternary_search(double l, double r){
    while (r - l > eps){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)){
            l = m1;
        }
        else {
            r = m2;
        }
    }
    return (l + r) / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double l, r;
    cin >> l >> r;
    cout << fixed << setprecision(5) << ternary_search(l, r) << endl;
    return 0;
}


