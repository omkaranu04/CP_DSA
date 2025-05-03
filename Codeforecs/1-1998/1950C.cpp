#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans;
        int hrs = (s[0] - 48) * 10 + (s[1] - 48);
        int hrs_12;
        if (hrs == 12 || hrs == 00)
            hrs_12 = 12;
        else
            hrs_12 = hrs % 12;

        if (hrs_12 <= 9)
        {
            ans += "0";
            ans += to_string(hrs_12);
        }
        else
            ans += to_string(hrs_12);

        ans += ":";
        ans += s[3];
        ans += s[4];
        if (hrs >= 12)
            ans += " PM";
        else
            ans += " AM";
        cout << ans << endl;
    }
    return 0;
}