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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2)
    {
        l1 = (l1 == NULL) ? headB : l1->next;
        l2 = (l2 == NULL) ? headA : l2->next;
    }
    return l1;
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

pair<ListNode *, ListNode *> GetList(vector<int> listA, vector<int> listB, int skipA, int skipB)
{
    ListNode *headA = GetList(listA);

    if (skipA == -1 && skipB == -1)
    {
        ListNode *headB = GetList(listB);
        return {headA, headB};
    }

    vector<int> temp;
    for (int i = 0; i < skipB; i++)
    {
        temp.push_back(listB[i]);
    }

    ListNode *headB = GetList(temp);

    ListNode *curA = headA;
    for (int i = 0; i < skipA; i++)
    {
        curA = curA->next;
    }

    if (!headB)
        headB = curA;
    else
    {
        ListNode *curB = headB;
        while (curB->next)
        {
            curB = curB->next;
        }
        curB->next = curA;
    }

    return {headA, headB};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> listA(n);

    for (int i = 0; i < n; i++)
    {
        cin >> listA[i];
    }

    int m;
    cin >> m;

    vector<int> listB(m);

    for (int i = 0; i < m; i++)
    {
        cin >> listB[i];
    }

    int skipA, skipB;
    cin >> skipA >> skipB;

    pair<ListNode *, ListNode *> temp = GetList(listA, listB, skipA, skipB);

    ListNode *headA = temp.first;
    ListNode *headB = temp.second;

    ListNode *ansHead = getIntersectionNode(headA, headB);

    if (ansHead)
    {
        cout << ansHead->val << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}