#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int level = 0;
    int blocks_needed = 1;
    int blocks_available = n;

    while (blocks_available >= blocks_needed)
    {
        level++;
        blocks_available -= blocks_needed;
        blocks_needed += level + 1;
    }

    cout << level << endl;

    return 0;
}
