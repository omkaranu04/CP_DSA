#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(ll H, ll W, ll x, ll y, const vector<string> &S)
{
    return (x >= 0 && x < H && y >= 0 && y < W && S[x][y] != '#');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> S(H);
    for (ll i = 0; i < H; i++)
        cin >> S[i];
    string T;
    cin >> T;

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    ll distinctHouses = 0;
    ll currX = X - 1, currY = Y - 1;

    if (S[currX][currY] == '@')
    {
        visited[currX][currY] = true;
        distinctHouses++;
    }

    for (char move : T)
    {
        ll nextX = currX, nextY = currY;
        if (move == 'L')
            nextY--;
        else if (move == 'R')
            nextY++;
        else if (move == 'U')
            nextX--;
        else if (move == 'D')
            nextX++;

        if (isValid(H, W, nextX, nextY, S))
        {
            currX = nextX;
            currY = nextY;

            if (S[currX][currY] == '@' && !visited[currX][currY])
            {
                visited[currX][currY] = true;
                distinctHouses++;
            }
        }
    }

    cout << (currX + 1) << " " << (currY + 1) << " " << distinctHouses << endl;
    return 0;
}
