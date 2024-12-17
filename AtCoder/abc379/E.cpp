#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        a[i] = (i + 1) * stoi(s.substr(i, 1));
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    ll sum = 0;
    ll i = 0;
    while (i < n || sum > 0)
    {
        if (i < n)
        {
            sum += a[n - i - 1];
        }
        ans += to_string(sum % 10);
        sum /= 10;
        i++;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}