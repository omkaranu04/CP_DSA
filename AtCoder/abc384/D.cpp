#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
bool solve()
{
    ll N, S;
    cin >> N >> S;

    vector<ll> A(2 * N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll sum = accumulate(A.begin(), A.end(), 0LL);
    S %= sum;
    for (ll i = N; i < 2 * N; i++)
    {
        A[i] = A[i - N];
    }
    set<ll> ps;
    ll curr = 0;
    ps.insert(curr);
    for (ll i = 0; i < 2 * N; i++)
    {
        curr += A[i];
        ps.insert(curr);
    }
    for (auto i : ps)
    {
        if (ps.count(i + S))
            return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        if (solve())
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}