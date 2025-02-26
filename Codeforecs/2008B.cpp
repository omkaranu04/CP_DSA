#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPerfectSquare(ll n)
{
    ll root = sqrt(n);
    return root * root == n;
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (!isPerfectSquare(n))
    {
        cout << "NO" << endl;
        return;
    }
    ll root = sqrt(n);
    string ans = "";
    string t1 = "", t2 = "";
    for (int i = 0; i < root; i++)
    {
        t1 += '1';
    }
    t2 += '1';
    for (int i = 1; i < root - 1; i++)
    {
        t2 += '0';
    }
    t2 += '1';
    ans += t1;
    for (int i = 1; i < root - 1; i++)
    {
        ans += t2;
    }
    ans += t1;
    if (ans == s)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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