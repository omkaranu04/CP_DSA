#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    ll num = N * B - M;
    ll den = B - A;
    if (num < 0 || num % den != 0)
    {
        cout << "No\n";
        return;
    }
    ll cnt = num / den;
    if (cnt >= 0 && cnt <= N)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}