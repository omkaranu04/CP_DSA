#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), random(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *random) : val(x), next(next), random(random) {}
};

ListNode *copyRandomList(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *x = head;
    while (x)
    {
        ListNode *y = new ListNode(x->val);
        y->next = x->next;
        x->next = y;
        x = y->next;
    }
    x = head;
    while (x)
    {
        if (x->random)
            x->next->random = x->random->next;
        x = x->next->next;
    }
    x = head;
    ListNode *nhead = head->next;
    while (x)
    {
        ListNode *y = x->next;
        x->next = y->next;
        if (y->next)
            y->next = y->next->next;
        x = x->next;
    }
    return nhead;
}

ListNode *GetList(vector<pair<int, int>> &num)
{
    int n = (int)num.size();
    vector<ListNode *> copy(n);

    ListNode *head = NULL;
    ListNode *cur = NULL;

    for (int i = 0; i < n; i++)
    {
        ListNode *temp = new ListNode(num[i].first);
        copy[i] = temp;
        if (!head)
        {
            head = temp;
            cur = temp;
        }
        else
        {
            cur->next = temp;
            cur = cur->next;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (num[i].second == -1)
            continue;
        copy[i]->random = copy[num[i].second];
    }

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> num(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i].first >> num[i].second;
    }

    ListNode *head = GetList(num);

    ListNode *ans = copyRandomList(head);

    while (ans)
    {
        cout << ans->val << " ";
        if (ans->random)
            cout << ans->random->val << "\n";
        else
            cout << "-1\n";
        ans = ans->next;
    }

    return 0;
}
