#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    string result(N, '-');
    if (N == 1)
    {
        cout << "=";
        return 0;
    }
    else if (N % 2 == 1)
    {
        result[N / 2] = '=';
    }
    else
    {
        result[N / 2 - 1] = '=';
        result[N / 2] = '=';
    }
    cout << result << endl;
    return 0;
}