#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll val = 0;
    ll q;
    cin >> q;
    while (q--)
    {
        ll t, i;
        cin >> t;
        if (t == 1)
        {
            cin >> i;
            if ((val & (1LL << i)))
                cout << "1\n";
            else
                cout << "0\n";
        }
        if (t == 2)
        {
            cin >> i;
            val |= (1LL << i);
        }
        if (t == 3)
        {
            cin >> i;
            val &= (~(1LL << i));
        }
        if (t == 4)
        {
            cin >> i;
            val ^= (1LL << i);
        }
        if (t == 5)
        {
            if (__builtin_popcountll(val) == 60)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        if (t == 6)
        {
            if (__builtin_popcountll(val) >= 1)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        if (t == 7)
        {
            if (__builtin_popcountll(val) == 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        if (t == 8)
        {
            cout << __builtin_popcountll(val) << "\n";
        }
        if (t == 9)
        {
            cout << val << "\n";
        }
    }
    return 0;
}