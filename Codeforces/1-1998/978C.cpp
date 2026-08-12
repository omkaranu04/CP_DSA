#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n, m;
    cin >> n >> m;
    long long int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    long long int numbers[n + 1];
    numbers[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        numbers[i] = numbers[i - 1] + a[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        long long int index = lower_bound(numbers, numbers + n + 1, b[i]) - numbers;
        cout << index << " " << b[i] - numbers[index - 1] << endl;
    }
    return 0;
}