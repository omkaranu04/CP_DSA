#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, a, b;
vector<ll> arr, dist;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    arr.resize(n);
    dist.resize(n, INT_MAX);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    return 0;
}