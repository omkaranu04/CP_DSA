#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, sum = 0;
        cin >> n;
        vector<long long int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
        }
        long long int oper = 0, count = 0;
        for (auto x : a)
        {
            if (x == 0 && count == 0)
                continue;
            if (x <= 0)
                count++;
            else
            {
                if (count > 0)
                    oper++;
                count = 0;
            }
        }
        if (count)
            oper++;
        cout << sum << " " << oper << endl;
    }
    return 0;
}