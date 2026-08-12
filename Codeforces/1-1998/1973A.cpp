#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        int total_points = p1 + p2 + p3;
        if (total_points % 2 == 1)
            cout << -1 << endl;
        else
        {
            int drawgames = min(total_points / 2, p1 + p2);
            cout << drawgames << endl;
        }
    }
    return 0;
}
