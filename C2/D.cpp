#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);

    for (int i = m-1; i >= 0; --i) {
        int d1 = num1[i]-'0';
        for (int j = n-1; j >= 0; --j) {
            int d2 = num2[j]-'0';
            int cur = d1 * d2 + res[i + j + 1];
            res[i + j + 1] = cur % 10;
            res[i + j] += cur / 10;
        }
    }
    string result;
    for (int num : res) {
        if (!(result.empty() && num == 0)) {
            result.push_back(num + '0');
        }
    }
    return result.empty() ? "0" : result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        cout << multiply(A, B) << endl;
    }
    return 0;
}