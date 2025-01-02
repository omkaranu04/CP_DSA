#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    ll a, b;
    cin >> s >> t;
    a = s.length();
    b = t.length();
    ll i = 0, j = 0;
    while (i < a && j < b)
    {
        if (s[i] != t[j])
        {
            cout << i + 1 << endl;
            return 0;
        }
        i++;
        j++;
    }
    if (i == a && j == b)
        cout << 0 << endl;
    else if (i == a)
        cout << j + 1 << endl;
    else
        cout << i + 1 << endl;

    return 0;
}