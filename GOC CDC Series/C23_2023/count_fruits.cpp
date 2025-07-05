#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXA = 1001;
using mask = bitset<MAXA>;
struct SegTree
{
    ll n;
    vector<mask> st;
    SegTree(ll &_n, vector<ll> &a) : n(_n), st(4 * n + 4) { build(1, 0, n - 1, a); }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;

    return 0;
}