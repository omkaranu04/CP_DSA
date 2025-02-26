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
        ll a;
        cin >> a;
        string x = to_string(a);
        bool flag = true;
        if (x.length() <= 2)
            flag = false;
        if (x[0] != '1')
            flag = false;
        if (x[1] != '0')
            flag = false;
        ll num = 0;
        for (int i = 2; i < x.length(); i++)
        {
            num = num * 10;
            num += (x[i] - '0');
            if (num == 0)
                flag = false;
        }
        if (num < 2)
            flag = false;
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}