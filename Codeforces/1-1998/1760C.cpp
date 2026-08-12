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
        int n;
        cin >> n;
        vector<int> a(n), t(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        t = a;
        sort(t.begin(), t.end());
        ll t1 = t[n - 1], t2 = t[n - 2];
        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != t1)
                ans.push_back(a[i] - t1);
            else
                ans.push_back(a[i] - t2);
        }
        for (auto v : ans)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}