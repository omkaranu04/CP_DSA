#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s;
        cin >> t;
        int ls = s.length(), lt = t.length();
        int lcm = (ls * lt) / __gcd(ls, lt);
        int mul_s = lcm / ls, mul_t = lcm / lt;
        string ress, rest;
        while (mul_s--)
        {
            ress += s;
        }
        while (mul_t--)
        {
            rest += t;
        }
        if (ress == rest)
        {
            string ans = ress.substr(0, lcm);
            cout << ans << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}