#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> count(M + 1, 0);
    for (int i = 0; i < N; i++)
    {
        if (A[i] >= 1 && A[i] <= M)
        {
            count[A[i]]++;
        }
    }

    bool all_present = true;
    for (int i = 1; i <= M; i++)
    {
        if (count[i] == 0)
        {
            all_present = false;
            break;
        }
    }

    if (!all_present)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] >= 1 && A[i] <= M)
        {
            count[A[i]]--;
            if (count[A[i]] == 0)
            {
                cout << (N - i) << endl;
                return 0;
            }
        }
    }

    return 0;
}