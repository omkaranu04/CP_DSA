#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
bool comp(string &a, string &b)
{
    if (a.length() != b.length())
        return a.length() > b.length();
    return a > b;
}
bool comp2(string &a, string &b)
{
    return a + b > b + a;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (auto &x : s)
        cin >> x;

    sort(s.begin(), s.end(), comp);

    vector<string> sel;
    for (ll i = 0; i < k; i++)
        sel.push_back(s[i]);

    bool nonZero = false;
    for (int i = 0; i < k; i++)
    {
        for (auto c : sel[i])
        {
            if (c != '0')
            {
                nonZero = true;
                break;
            }
        }
        if (nonZero)
            break;
    }

    if (!nonZero)
    {
        for (ll i = k; i < n; i++)
        {
            bool flag = false;
            for (auto c : s[i])
            {
                if (c != '0')
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                sel[k - 1] = s[i];
                break;
            }
        }
    }
    sort(sel.begin(), sel.end(), comp2);
    string ans = "";
    for (auto x : sel)
        ans += x;
    ll i = 0;
    while (i < ans.length() - 1 && ans[i] == '0')
        i++;
    ans = ans.substr(i);
    cout << ans << endl;
    return 0;
}