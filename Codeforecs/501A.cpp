#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int vasya = max((3 * b) / 10, b - (b / 250) * d);
    int misha = max((3 * a) / 10, a - (a / 250) * c);
    if (misha > vasya)
        cout << "Misha" << endl;
    else if (vasya > misha)
        cout << "Vasya" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}