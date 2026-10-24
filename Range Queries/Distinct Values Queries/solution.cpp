#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using ld = long double;

struct BIT
{
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, int val)
    {
        while (idx <= n)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    {
        int ans = 0;
        while (idx > 0)
        {
            ans += tree[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    int range(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    // coordinate compression
    vector<pair<int, int>> elements(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        elements[i] = {arr[i], i};
    }
    sort(all(elements));
    int curr = 1;
    for (int i = 1; i <= n; ++i)
    {
        arr[elements[i].second] = curr;
        while (i + 1 <= n && elements[i + 1].first == elements[i].first)
        {
            i++;
            arr[elements[i].second] = curr;
        }
        curr++;
    }

    vector<vector<pair<int, int>>> byR(n + 1);
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        byR[b].push_back({a, i});
    }

    BIT bit(n);
    vector<int> lastOccurence(n + 1, -1);
    vector<int> ans(q);

    for (int i = 1; i <= n; ++i)
    {
        if (lastOccurence[arr[i]] != -1)
        {
            bit.update(lastOccurence[arr[i]], -1);
        }
        bit.update(i, 1);
        lastOccurence[arr[i]] = i;

        if (!byR[i].empty())
        {
            for (auto [l, qr] : byR[i])
            {
                ans[qr] = bit.range(l, i);
            }
        }
    }

    for (int i = 0; i < q; ++i)
    {
        cout << ans[i] << '\n';
    }
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}