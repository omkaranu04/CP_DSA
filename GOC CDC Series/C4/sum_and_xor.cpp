#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll S, X, A, B;

void solve()
{
    cin >> S >> X;
    if (S < X || ((S - X) & 1))
    {
        cout << "-1 -1\n";
        return;
    }
    A = 0, B = 0;
    ll K = (S - X) / 2;
    for (ll i = 0; i < 64; i++)
    {
        ll xb = (X >> i) & 1;
        ll kb = (K >> i) & 1;

        if (xb == 0 && kb == 1)
        {
            A |= (1LL << i);
            B |= (1LL << i);
        }
        else if (xb == 1 && kb == 0)
        {
            B |= (1LL << i);
        }
        else if (xb == 0 && kb == 0)
        {
            // A=0, B=0, do nothing
        }
        else
        {
            cout << "-1 -1\n";
            return;
        }
    }

    if (A > B)
        swap(A, B);
    cout << A << " " << B << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    cin >> q;
    while (q--)
        solve();
}
