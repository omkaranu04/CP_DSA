#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;

        for (long long q = 1;; q++)
        {
            long long left = A * q / B;
            if (A * q % B != 0)
                left++;

            long long right = (C * q - 1) / D;

            if (left <= right)
            {
                bool found = false;
                for (long long p = left; p <= min(right, left + 100); p++)
                {
                    if (A * q < p * B && p * D < C * q)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    cout << q << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}