#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    
    ll bigSize = n - m + 1;
    ll kmax = bigSize * (bigSize - 1) / 2;
    ll q = n / m;
    ll r = n % m;
    ll edgesInLarge = (q + 1) * q / 2;
    ll edgesInSmall = q * (q - 1) / 2;

    ll kmin = r * edgesInLarge + (m - r) * edgesInSmall;

    cout << kmin << " " << kmax << "\n";
    return 0;
}
