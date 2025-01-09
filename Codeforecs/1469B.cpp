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
        int r[n], ps1[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
        }

        ps1[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            ps1[i] = ps1[i - 1] + r[i - 1];
        }


        int m;
        cin >> m;
        int b[m], ps2[m + 1];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        ps2[0] = 0;
        for (int i = 1; i < m + 1; i++)
        {
            ps2[i] = ps2[i - 1] + b[i - 1];
        }


        int max1, max2;
        max1 = *max_element(ps1, ps1 + (n + 1));
        max2 = *max_element(ps2, ps2 + (m + 1));
        cout << max1 + max2 << endl;
    }

    return 0;
}
