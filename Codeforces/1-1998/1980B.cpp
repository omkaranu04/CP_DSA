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
        ll n, f, k;
        cin >> n >> f >> k;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int fav_val = a[f];
        sort(a.begin() + 1, a.end());
        reverse(a.begin() + 1, a.end());
        int first_index = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == fav_val)
            {
                first_index = i;
                break;
            }
        }
        int last_index = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == fav_val)
                last_index = i;
        }
        if ((k) > last_index)
            cout << "YES" << endl;
        else if ((k) < first_index)
            cout << "NO" << endl;
        else if (last_index == k)
            cout << "YES" << endl;
        else
            cout << "MAYBE" << endl;
    }
    return 0;
}