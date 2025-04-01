#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = rev + "#" + s;
    int m = combined.size();

    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && combined[i] != combined[j])
            j = pi[j - 1];
        if (combined[i] == combined[j])
            j++;
        pi[i] = j;
    }

    int L = pi[m - 1];

    string toAppend = s.substr(0, n - L);
    reverse(toAppend.begin(), toAppend.end());

    cout << s + toAppend << "\n";

    return 0;
}