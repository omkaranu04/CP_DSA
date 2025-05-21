#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    int count = 0;

    for (long long k = 2; k * (k + 1) <= 2 * N; ++k)
    {
        long long numerator = 2 * N - k * (k - 1);
        if (numerator % (2 * k) == 0)
        {
            long long a = numerator / (2 * k);
            if (a > 0)
                count++;
        }
    }

    cout << count << endl;
    return 0;
}
