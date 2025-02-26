#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> A[i][j];
        }
    }

    int current = 1;

    for (int i = 1; i <= N; ++i)
    {
        if (current >= i)
        {
            current = A[current - 1][i - 1];
        }
        else
        {
            current = A[i - 1][current - 1];
        }
    }

    cout << current << endl;

    return 0;
}