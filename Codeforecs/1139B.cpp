#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n;
    cin >> n;
    vector<long long int> a(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    long long int curr = 1e18;
    long long int bought = 0;
    for (int i = n; i >= 1; i--)
    {
        curr = min(curr - 1, a[i]);
        curr = max(0LL, curr);
        bought += curr;
    }
    cout << bought << endl;
    return 0;
}