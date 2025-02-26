#include <iostream>
#include <vector>
using namespace std;
bool canBeSortedByOneSwap(const vector<int> &A)
{
    vector<int> sortedA = {1, 2, 3, 4, 5};

    int count = 0;
    int first = -1, second = -1;

    for (int i = 0; i < 5; ++i)
    {
        if (A[i] != sortedA[i])
        {
            count++;
            if (first == -1)
            {
                first = i;
            }
            else
            {
                second = i;
            }
        }
    }

    if (count == 2)
    {
        if (second == first + 1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> A(5);
    for (int i = 0; i < 5; ++i)
    {
        cin >> A[i];
    }
    if (canBeSortedByOneSwap(A))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}