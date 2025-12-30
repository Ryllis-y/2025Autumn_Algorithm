#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000007;
bool isPrime[maxn];
vector<int> primes;

void sieve(int n){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++){
        if (isPrime[i]){
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++){
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0){
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    sieve(n);
    while (q--){
        int k;
        cin >> k;
        cout << primes[k - 1] << endl;
    }
    return 0;
}


