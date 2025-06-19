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

ListNode *merge2Lists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val > l2->val)
        swap(l1, l2);

    // l1 has the smaller element now
    ListNode *head = l1;
    while (l1 && l2)
    {
        ListNode *prev = NULL;
        while (l1 && l1->val <= l2->val)
        {
            prev = l1;
            l1 = l1->next;
        }
        prev->next = l2;
        swap(l1, l2);
    }
    return head;
}
ListNode *mergeKLists(vector<ListNode *> heads)
{
    if (heads.empty())
        return NULL;
    int n = heads.size();
    while (n > 1)
    {
        int half = (n + 1) / 2;
        for (int i = 0; i < n / 2; i++)
            heads[i] = merge2Lists(heads[i], heads[i + half]);
        n = half;
    }
    return heads[0];
}

ListNode *GetList(vector<int> &num)
{
    ListNode *head = nullptr;

    if (num.empty())
    {
        return head;
    }

    ListNode *cur = head;

    for (int i = 0; i < (int)num.size(); i++)
    {
        ListNode *temp = new ListNode(num[i]);
        if (!cur)
        {
            cur = temp;
            head = cur;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
    }

    return head;
}

vector<ListNode *> GetList(int K, vector<vector<int>> &num)
{
    vector<ListNode *> head(K);
    for (int i = 0; i < K; i++)
    {
        head[i] = GetList(num[i]);
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

    vector<ListNode *> head = GetList(K, num);

    ListNode *mergeHead = mergeKLists(head);

    while (mergeHead)
    {
        cout << mergeHead->val << " ";
        mergeHead = mergeHead->next;
    }
    cout << "\n";

    return 0;
}
