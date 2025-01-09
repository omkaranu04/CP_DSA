#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, count = 0;
        cin >> n;
        long long int a[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i] - (i);
        }
        unordered_map<long long int, long long int> freq;
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            freq[a[i]]++;
        }
        for (const auto &[key, value] : freq)
        {
            sum += (value * (value - 1)) / 2;
        }
        cout << sum << endl;
    }
    return 0;
}
