#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, c;
        cin >> n >> c;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i] + i + 1;
        }
        sort(a, a + n);
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            count++;
            if (sum > c)
            {
                count = count - 1;
                break;
            }
        }
        cout << count << endl;
    }

    return 0;
}
