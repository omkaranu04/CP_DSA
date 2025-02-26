#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> segments;
    vector<int> idx = {0};
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] != s[i])
            idx.push_back(i);
    }
    idx.push_back(n);
    for (size_t i = 0; i < idx.size() - 1; i++)
    {
        segments.push_back(s.substr(idx[i], idx[i + 1] - idx[i]));
    }

    int kth_1_idx;
    if (s[0] == '0')
    {
        kth_1_idx = 2 * k - 1;
    }
    else
    {
        kth_1_idx = 2 * k - 2;
    }

    if (kth_1_idx - 1 >= 0 && kth_1_idx < segments.size())
    {
        swap(segments[kth_1_idx - 1], segments[kth_1_idx]);
    }

    string result;
    for (const string &segment : segments)
    {
        result += segment;
    }

    cout << result << "\n";
    return 0;
}