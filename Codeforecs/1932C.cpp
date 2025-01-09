#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    ll left = 0;
    ll right = n - 1;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'L')
            left++;
        else
            right--;
    }
    vector<ll> b;
    ll prod = a[left];
    b.push_back(prod % m);
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            left--;
            prod = (prod * a[left]) % m;
            b.push_back(prod % m);
        }
        else
        {
            right++;
            prod = (prod * a[right]) % m;
            b.push_back(prod % m);
        }
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}