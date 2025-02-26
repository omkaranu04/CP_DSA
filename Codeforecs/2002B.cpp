#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool flag1 = true, flag2 = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                flag1 = false;
            if (a[i] != b[n - i - 1])
                flag2 = false;
        }
        if (flag1 || flag2)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}