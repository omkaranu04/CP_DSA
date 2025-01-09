#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isGood(vector<ll> &a)
{
    ll g = __gcd(a[0], a[1]);
    for (int i = 1; i < a.size() - 1; i++)
    {
        int cur = __gcd(a[i], a[i + 1]);
        if (cur < g)
            return false;
        g = cur;
    }
    return true;
}
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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int index = -1;
        int x = __gcd(a[0], a[1]);
        for (int i = 1; i < n - 1; i++)
        {
            int curr = __gcd(a[i], a[i + 1]);
            if (curr < x)
            {
                index = i;
                break;
            }
            x = curr;
        }
        if (index == -1)
        {
            cout << "YES" << endl;
            continue;
        }
        vector<ll> b1, b2, b3;
        for (int i = 0; i < n; i++)
        {
            if (i != index - 1)
                b1.push_back(a[i]);
            if (i != index)
                b2.push_back(a[i]);
            if (i != index + 1)
                b3.push_back(a[i]);
        }
        bool ans = isGood(b1) || isGood(b2) || isGood(b3);
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}