#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int b[7];
        for (int i = 0; i < 7; i++)
        {
            cin >> b[i];
        }

        sort(b, b + 7);
        cout << b[6] - b[5] << " " << b[6] - b[4] << " " << b[6] - b[3] << endl;
    }

    return 0;
}
