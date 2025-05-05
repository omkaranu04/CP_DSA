#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int MAXN = 200005;
vector<int> parent(MAXN), deg(MAXN);
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        deg[A]++;
        deg[B]++;
        unite(A, B);
    }
    if (M != N)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (deg[i] != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    int representative = find(1);
    for (int i = 2; i <= N; ++i)
    {
        if (find(i) != representative)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}