#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node
{
    ll val;
    Node *next;
    Node(ll _val = 0, Node *ptr = NULL) : val(_val), next(ptr) {};
};
Node *CreateList(vector<ll> &a)
{
    Node *head = NULL;
    if (a.empty())
        return head;
    Node *curr = head;
    for (ll i = 0; i < a.size(); i++)
    {
        Node *tmp = new Node(a[i]);
        if (curr == NULL)
        {
            curr = tmp;
            head = curr;
        }
        else
        {
            curr->next = tmp;
            curr = tmp;
        }
    }
    return head;
}
Node *rotateList(Node *head, ll k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    ll sz = 1;
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        sz++;
    }
    k %= sz;
    if (k == 0)
        return head;

    tail->next = head;
    Node *prev, *curr = head;
    for (ll i = 0; i < sz - k; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    head = curr;

    return head;
}
Node *removeNode(Node *head, ll k)
{
    if (head == NULL)
        return NULL;
    ll sz = 1;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
        sz++;
    }
    if (k == sz)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    Node *prev, *curr = head;
    for (ll i = 0; i < sz - k; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
    return head;
}
Node *removeDup(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    map<ll, ll> mp;
    Node *prev = NULL, *curr = head;
    while (curr)
    {
        if (mp[curr->val] != 0)
        {
            Node *toDel = curr;
            curr = curr->next;
            prev->next = curr;
            delete toDel;
        }
        else
        {
            mp[curr->val]++;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    // cin >> k;
    Node *head = CreateList(a);
    head = removeDup(head);
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}