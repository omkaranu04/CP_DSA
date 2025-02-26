#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    queue<int> q;
    bool flag = false;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (flag)
            cout << t << " ";
        else
            q.push(t);
        flag = !flag;
    }
    return 0;
}