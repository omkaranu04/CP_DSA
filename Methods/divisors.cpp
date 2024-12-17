#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int sum = 0, cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << endl;

            cnt++;
            sum += i;
            if (n / i != i)
            {
                cnt++;
                sum += n / i;
            }
        }
    }
    cout << cnt << " " << sum << endl;
    return 0;
}