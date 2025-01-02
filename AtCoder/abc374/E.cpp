#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, x;
vector<ll> a, p, b, q;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    a.resize(n);
    p.resize(n);
    b.resize(n);
    q.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    return 0;
}