#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        long long n, i, c, d, ans = 0;
        cin >> n >> c >> d;

        vector<long long> arr(n);
        vector<long long> brr(n);

        for (i = 0; i < n; i++)
            cin >> arr[i];

        for (i = 0; i < n; i++)
            cin >> brr[i];

        ordered_set s;
        for (i = 0; i < n; i++)
        {
            ans += s.order_of_key({arr[i] - brr[i] + d, i});
            s.insert({arr[i] - brr[i] + c, i});
        }

        cout << ans << "\n";
    }

    return 0;
}
