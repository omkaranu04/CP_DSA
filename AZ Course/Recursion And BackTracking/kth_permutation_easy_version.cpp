// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// ll cnt = 0;
// void generate_permutations(map<ll, ll> &mp, ll level, ll n, vector<ll> &tmp, ll k)
// {
//     if (level == n)
//     {
//         cnt++;
//         if (cnt == k)
//         {
//             for (auto x : tmp)
//             {
//                 cout << x << " ";
//             }
//             cout << endl;
//             exit(0);
//         }
//         return;
//     }
//     for (auto x : mp)
//     {
//         if (x.second > 0)
//         {
//             tmp.push_back(x.first);
//             mp[x.first]--;
//             generate_permutations(mp, level + 1, n, tmp, k);
//             mp[x.first]++;
//             tmp.pop_back();
//         }
//     }
// }
// void solve()
// {
//     ll n, k;
//     cin >> n >> k;
//     map<ll, ll> mp;
//     for (ll i = 0; i < n; i++)
//     {
//         mp[i + 1]++;
//     }
//     vector<ll> tmp;
//     generate_permutations(mp, 0, n, tmp, k);
// }
// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ll t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll factorial(ll i)
{
    if (i == 0)
    {
        return 1;
    }
    return i * factorial(i - 1);
}
void solve2(vector<ll> &a, ll k)
{
    ll n = a.size();
    k--;
    vector<ll> ans;
    ll fact = factorial(n - 1);
    while (1)
    {
        ans.push_back(a[k / fact]);
        a.erase(a.begin() + k / fact);
        if (a.size() == 0)
            break;
        k %= fact;
        fact /= a.size();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n <= 13)
    {
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        solve2(a, k);
    }
    else
    {
        vector<ll> a;
        for (ll i = 1; i < n - 12; i++)
        {
            cout << i << " ";
        }
        for (ll i = n - 12; i <= n; i++)
        {
            a.push_back(i);
        }
        solve2(a, k);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}