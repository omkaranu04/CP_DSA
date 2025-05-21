#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> x[i];
    vector<ll> pos(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        pos[x[i]] = i;
    ll count = 1;
    ll l = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (l > pos[i])
            count++;
        l = pos[i];
    }
    // cout << count << endl;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        ll s1 = x[a], s2 = x[b];
        swap(x[a], x[b]); // swap in original array
        if (pos[s1 - 1] <= pos[s1] && pos[s1 - 1] > b)
            count++;
        if (pos[s1 - 1] > pos[s1] && pos[s1 - 1] <= b)
            count--;
        if (pos[s1] <= pos[s1 + 1] && pos[s1 + 1] < b)
            count++;
        if (pos[s1] > pos[s1 + 1] && pos[s1 + 1] >= b)
            count--;
        pos[s1] = b;
        if (pos[s2 - 1] <= pos[s2] && pos[s2 - 1] > a)
            count++;
        if (pos[s2 - 1] > pos[s2] && pos[s2 - 1] <= a)
            count--;
        if (pos[s2] <= pos[s2 + 1] && pos[s2 + 1] < a)
            count++;
        if (pos[s2] > pos[s2 + 1] && pos[s2 + 1] >= a)
            count--;
        pos[s2] = a;
        cout << count << endl;
    }
    return 0;
}