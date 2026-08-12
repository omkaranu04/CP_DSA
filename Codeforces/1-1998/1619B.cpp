#include <bits/stdc++.h>
using namespace std;
bool isSquare(int num)
{
    int root = sqrt(num);
    return (root * root) == num;
}
bool isCube(int num)
{
    int root = cbrt(num);
    return (root * root * root) == num;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n;
        cin >> n;
        set<int> sqandcub;
        for (int j = 1; j * j <= n; j++)
        {
            sqandcub.insert(j * j);
        }
        for (int j = 1; j * j * j <= n; j++)
        {
            sqandcub.insert(j * j * j);
        }
        cout << sqandcub.size() << endl;
    }
    return 0;
}
