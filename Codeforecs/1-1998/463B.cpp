#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int energy = 0, cost = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        energy += x - y;
        if (energy < 0)
        {
            cost += -energy;
            energy = 0;
        }
        x = y;
    }
    cout << cost << endl;
    return 0;
}