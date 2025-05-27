#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int year = stoi(s);
        bool found = false;
        int root = (int)sqrt(year);
        if (root * root == year)
        {
            cout << 0 << " " << root << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
