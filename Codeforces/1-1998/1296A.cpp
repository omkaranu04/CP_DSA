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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int odd_count = 0, even_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                even_count++;
            else
                odd_count++;
        }
        if ((odd_count % 2 == 0 && even_count > 0 && even_count != n) || odd_count % 2 != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}