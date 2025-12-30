#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    vector<int> a;
    
    BigInt(const string& s = "0") {
        for (int i = s.size() - 1; i >= 0; i--)
            a.push_back(s[i] - '0');
        trim();
    }
    
    void trim() {
        while (a.size() > 1 && a.back() == 0)
            a.pop_back();
    }
    
    BigInt operator*(const BigInt& b) const {
        int n = a.size(), m = b.a.size();
        vector<int> res(n + m, 0);
        
        for (int i = 0; i < n; i++) {
            int carry = 0;
            for (int j = 0; j < m; j++) {
                int sum = a[i] * b.a[j] + res[i + j] + carry;
                res[i + j] = sum % 10;
                carry = sum / 10;
            }
            if (carry) res[i + m] += carry;
        }
        
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] >= 10) {
                res[i + 1] += res[i] / 10;
                res[i] %= 10;
            }
        }
        
        BigInt ans;
        ans.a = res;
        ans.trim();
        return ans;
    }
    
    friend istream& operator>>(istream& in, BigInt& x) {
        string s;
        in >> s;
        x = BigInt(s);
        return in;
    }
    
    friend ostream& operator<<(ostream& out, const BigInt& x) {
        for (int i = x.a.size() - 1; i >= 0; i--)
            out << x.a[i];
        return out;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        BigInt a, b;
        cin >> a >> b;
        cout << a * b << "\n";
    }
    
    return 0;
}