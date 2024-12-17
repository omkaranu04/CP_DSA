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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (a[n - 1] == a[0])
            cout << -1 << endl;
        else
        {
            int cnt = 0;
            while (a[cnt] == a[0])
                cnt++;
            cout << cnt << " " << n - cnt << endl;
            for (int i = 0; i < cnt; i++)
                cout << a[i] << " ";
            cout << endl;
            for (int i = cnt; i < n; i++)
                cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}