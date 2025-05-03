#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(make_pair(x, i + 1));
    }
    sort(a.begin(), a.end());
    int days_sum = 0;
    int i = 0;
    vector<int> answer;
    while (i < n && a[i].first + days_sum <= k)
    {
        answer.push_back(a[i].second);
        days_sum += a[i].first;
        i++;
    }
    cout << answer.size() << endl;
    for (auto i : answer)
    {
        cout << i << " ";
    }
    return 0;
}