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
        vector<char> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'U')
                count++;
        }
        if (count % 2 != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}