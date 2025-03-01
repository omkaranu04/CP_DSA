#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX;

struct State
{
    int node;
    bool reversed;
    long long cost;

    State(int _node, bool _reversed, long long _cost) : node(_node), reversed(_reversed), cost(_cost) {}

    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }
};

int main()
{
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> g(N + 1);
    vector<vector<int>> rg(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    vector<vector<long long>> d(N + 1, vector<long long>(2, INF));
    d[1][0] = 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(State(1, false, 0));

    while (!pq.empty())
    {
        State curr = pq.top();
        pq.pop();

        int node = curr.node;
        bool reversed = curr.reversed;
        long long current_cost = curr.cost;

        if (current_cost > d[node][reversed])
            continue;

        if (node == N)
            break;

        const vector<vector<int>> &graph = reversed ? rg : g;
        for (int next_node : graph[node])
        {
            long long new_cost = current_cost + 1;
            if (new_cost < d[next_node][reversed])
            {
                d[next_node][reversed] = new_cost;
                pq.push(State(next_node, reversed, new_cost));
            }
        }

        long long reversal_cost = current_cost + X;
        bool new_reversed = !reversed;
        if (reversal_cost < d[node][new_reversed])
        {
            d[node][new_reversed] = reversal_cost;
            pq.push(State(node, new_reversed, reversal_cost));
        }
    }

    long long result = min(d[N][0], d[N][1]);
    cout << result << endl;

    return 0;
}