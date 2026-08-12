#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            a.push_back(i);
        }
        cout << 2 << endl;
        for (int i = 1; i <= n - 1; i++)
        {
            cout << a[a.size() - 1] << " " << a[a.size() - 2] << endl;
            int to_be = (a[a.size() - 1] + a[a.size() - 2] + 1) / 2;
            a.pop_back();
            a.pop_back();
            a.push_back(to_be);
        }
    }
    return 0;
}