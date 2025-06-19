#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getKIntersectionNode(vector<ListNode *> &lists)
{
    int k = lists.size();
    if (k == 0)
        return NULL;
    for (auto p : lists)
    {
        if (p == NULL)
            return NULL;
    }
    map<ListNode *, int> mp;
    for (int i = 0; i < k; i++)
    {
        for (ListNode *curr = lists[i]; curr; curr = curr->next)
        {
            mp[curr]++;
        }
    }

    for (ListNode *curr = lists[0]; curr; curr = curr->next)
    {
        if (mp[curr] == k)
            return curr;
    }
    return NULL;
}

vector<ListNode *> GetList(vector<vector<int>> &num, int K)
{
    vector<ListNode *> head(K), cur(K);

    for (int i = 0; i < K; i++)
    {
        head[i] = NULL;
        cur[i] = NULL;
    }

    map<int, ListNode *> M;

    for (int i = 0; i < K; i++)
    {
        for (int u : num[i])
        {
            if (M.find(u) != M.end())
            {
                if (!head[i])
                {
                    head[i] = M[u];
                    cur[i] = head[i];
                }
                else
                {
                    cur[i]->next = M[u];
                    cur[i] = cur[i]->next;
                }
                break;
            }
            else
            {
                ListNode *temp = new ListNode(u);
                if (!head[i])
                {
                    head[i] = temp;
                    cur[i] = head[i];
                }
                else
                {
                    cur[i]->next = temp;
                    cur[i] = cur[i]->next;
                }
                M[u] = temp;
            }
        }
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;

    vector<vector<int>> num(K);

    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;

            num[i].push_back(x);
        }
    }

    vector<ListNode *> head = GetList(num, K);

    ListNode *ans = getKIntersectionNode(head);

    if (ans)
        cout << ans->val << "\n";
    else
        cout << "-1\n";

    return 0;
}
