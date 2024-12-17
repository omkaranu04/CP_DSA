#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll n = s.length();
    string t;
    for (char c : s)
    {
        if (isupper(c))
            t += tolower(c);
        else
            t += toupper(c);
    }
    cout << t << endl;
    ll q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;
        k--;
        ll q = (k) / n;
        ll r = (k) % n;
        if (__builtin_popcountll(q) % 2 == 0)
        {
            cout << s[r] << " ";
        }
        else
        {
            cout << t[r] << " ";
        }
    }
    return 0;
}