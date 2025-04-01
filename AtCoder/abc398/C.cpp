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
    vector<ll> A(N);
    unordered_map<ll, ll> freq;
    unordered_map<ll, ll> index;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        freq[A[i]]++;
        index[A[i]] = i + 1;
    }

    ll max_value = -1, ans = -1;
    for (auto &[num, count] : freq)
    {
        if (count == 1 && num > max_value)
        {
            max_value = num;
            ans = index[num];
        }
    }
    cout << ans << endl;
    return 0;
}