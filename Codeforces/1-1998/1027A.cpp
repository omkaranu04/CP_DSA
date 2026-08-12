#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool o = true;
        for (int i = 0; i < n; i++)
        {
            int k = abs(s[i] - s[n - i - 1]);
            if (k > 2 || k % 2 == 1)
            {
                o = false;
                break;
            }
        }
        cout << (o ? "YES" : "NO") << endl;
    }
    return 0;
}