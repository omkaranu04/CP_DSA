#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int x[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> x[i];
    }
    long long int max = x[0];
    for (int i = 1; i < 4; i++)
    {
        if (x[i] > max)
            max = x[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (max - x[i] != 0)
            cout << max - x[i] << '\t';
    }
    return 0;
}
