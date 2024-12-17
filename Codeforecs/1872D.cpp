#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, x, y;
        cin >> n >> x >> y;

        long long int low = 1;
        long long int high = n;
        long long int sum = 0;

        for (long long int i = 1; i <= n; i++)
        {
            if (i % x == 0 && i % y != 0)
            {
                sum += high;
                high--;
            }
            else if (i % y == 0 && i % x != 0)
            {
                sum -= low;
                low++;
            }
        }

        cout << sum << endl;
    }
    return 0;
}
