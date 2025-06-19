#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Check if with bit‐mask "mask" we can make A non‐decreasing,
// where each A[i] may be increased by ORing any submask of "mask".
bool can_sort_with_mask(const vector<ll> &A, ll mask)
{
    ll last = 0;
    for (ll a : A)
    {
        ll low = a;           // minimum we can achieve at this position
        ll high = (a & ~mask) // bits we can't change
                  | mask;     // plus we can turn on all bits in mask
        // we need to pick y in [low, high] with y >= last:
        ll y = max(last, low);
        if (y > high)
            return false;
        last = y;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        // If already non-decreasing, zero operations needed
        bool sorted = true;
        for (int i = 1; i < N; i++)
        {
            if (A[i] < A[i - 1])
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
        {
            cout << 0 << "\n";
            continue;
        }

        // Try increasing masks: mask_j = (1<<(j+1)) - 1,
        // minimal k with that mask is k = 2^j.
        ll answer = -1;
        for (int j = 0; j <= 30; j++)
        {
            ll mask = ((1LL << (j + 1)) - 1);
            if (can_sort_with_mask(A, mask))
            {
                answer = (1LL << j);
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}