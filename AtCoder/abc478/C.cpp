#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &x : A)
        cin >> x;
    vector<ll> B = A;
    sort(B.begin(), B.end());
    bool ff = true, bf = true;
    ll f = 0, b = 0;
    for (ll i = 0; i < N; i++)
    {
        if (A[i] == B[i] && ff)
            f++;
        if (A[i] != B[i] && ff)
            ff = false;
    }
    for (ll i = N - 1; i >= 0; i--)
    {
        if (A[i] == B[i] && bf)
            b++;
        if (A[i] != B[i] && bf)
            bf = false;
    }
    // cout << f << " " << b << endl;
    ll unsorted = N - f - b;
    if (unsorted > K)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}