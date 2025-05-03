#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int p[n], count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == (i + 1))
                count++;
        }
        int answer = count / 2 + count % 2;
        cout << answer << endl;
    }
    return 0;
}