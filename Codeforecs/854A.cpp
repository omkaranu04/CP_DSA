#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n;
    a = 1;
    b = n - 1;
    float max = (float)a / (float)b;
    float frac;
    int outa, outb;
    while (a < b)
    {
        frac = (float)a / (float)b;
        if (frac >= max && __gcd(a, b) == 1)
        {
            max = frac;
            outa = a;
            outb = b;
        }
        a++;
        b--;
    }
    cout << outa << " " << outb << endl;
    return 0;
}
