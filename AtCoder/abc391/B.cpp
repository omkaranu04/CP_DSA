#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkPattern(const vector<string> &S, const vector<string> &T, int startRow, int startCol, int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (S[startRow + i][startCol + j] != T[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> findPattern(const vector<string> &S, const vector<string> &T, int N, int M)
{
    for (int i = 0; i <= N - M; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            if (checkPattern(S, T, i, j, M))
            {
                return {i + 1, j + 1};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    vector<string> T(M);
    for (int i = 0; i < M; i++)
    {
        cin >> T[i];
    }

    pair<int, int> result = findPattern(S, T, N, M);

    cout << result.first << " " << result.second << endl;

    return 0;
}