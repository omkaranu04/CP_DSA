#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n, k, answer;
    cin >> n >> k;
    if (k <= (n + 1) / 2)
    {
        answer = k * 2 - 1;
    }
    else
    {
        answer = (k - (n + 1) / 2) * 2;
    }
    cout << answer << endl;
    return 0;
}