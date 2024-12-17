#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    bool is_prime = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return 0;
}