#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
    struct HeapNode
    {
        int val, lvl;
        bool operator>(const HeapNode &n) const
        {
            return val > n.val;
        }
    };

public:
    pair<int, int> shortestRangeBST(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        // building level wise traversal
        vector<vector<int>> levels;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            TreeNode *node = x.first;
            int lvl = x.second;

            if (levels.size() == lvl)
                levels.emplace_back();
            levels[lvl].push_back(node->data);

            if (node->left)
                q.push({node->left, lvl + 1});
            if (node->right)
                q.push({node->right, lvl + 1});
        }

        int k = levels.size();
        if (k == 1)
        {
            int mn = *min_element(levels[0].begin(), levels[0].end());
            return {mn, mn};
        }

        // sort each level
        for (auto &v : levels)
            sort(v.begin(), v.end());

        // finding the smallest range
        vector<int> idx(k, 0);
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> pq;
        int currmax = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            pq.push({levels[i][0], i});
            currmax = max(currmax, levels[i][0]);
        }
        int bestlen = INT_MAX;
        int bestl = 0, bestr = 0;
        while (true)
        {
            int currmin = pq.top().val;
            int lvl = pq.top().lvl;

            int currlen = currmax - currmin;
            if (currlen < bestlen || (currlen == bestlen && currmin < bestl))
            {
                bestlen = currlen;
                bestl = currmin;
                bestr = currmax;
            }

            pq.pop();
            idx[lvl]++;
            if (idx[lvl] == levels[lvl].size())
                break;

            int nextlevel = levels[lvl][idx[lvl]];
            pq.push({nextlevel, lvl});
            currmax = max(currmax, nextlevel);
        }
        return {bestl, bestr};
    }
};

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    vector<string> dat;
    string t;
    for (auto c : data)
    {
        if (c == ',')
        {
            dat.push_back(t);
            t.clear();
        }
        else
            t.push_back(c);
    }
    dat.push_back(t);
    int i = 0;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoll(dat[0]));
    q.push(root);
    auto cur = root;
    i++;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (dat[i] != "x")
        {
            x->left = new TreeNode(stoll(dat[i]));
            q.push(x->left);
        }
        i++;
        if (dat[i] != "x")
        {
            x->right = new TreeNode(stoll(dat[i]));
            q.push(x->right);
        }
        i++;
    }
    return root;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto root = deserialize(s);
    Solution sol;
    auto ans = sol.shortestRangeBST(root);
    cout << ans.first << " " << ans.second << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}