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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string ans = "";
        vector<ll> hash(26, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (hash[j] == a[i])
                {
                    ans += (char)(j + 'a');
                    hash[j]++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}