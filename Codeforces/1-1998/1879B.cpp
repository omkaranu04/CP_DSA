#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int row[n] = {0}, column[n] = {0};
        long long int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        long long int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += (a[i] + b[0]);
        }
        for (int i = 0; i < n; i++)
        {
            sum2 += (a[0] + b[i]);
        }
        cout << min(sum1, sum2) << endl;
    }
    return 0;
}