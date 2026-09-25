#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (auto &x : a)
        cin >> x;
    ll c1 = 0, c2 = 0, c3 = 0;
    for (auto x : a)
    {
        ll p = ((x + 999) / 1000) * 1000;
        ll c = p - x;
        c3 += c / 100;
        c %= 100;
        c2 += c / 10;
        c %= 10;
        c1 += c;
    }
    cout << c1 << " " << c2 << " " << c3 << endl;
    return 0;
}