#include <bits/stdc++.h>
using namespace std;
int difference(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i <= (n - 1) / 2; i++)
        {
            sum = sum + difference(a[i], a[n - 1 - i]);
        }
        cout << sum << endl;
    }
    return 0;
}
