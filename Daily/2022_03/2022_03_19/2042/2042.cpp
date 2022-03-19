#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, k, x, y, z;
ll seg[4000000];

ll update(ll pos, ll val, ll node, ll x, ll y) {
    if (pos < x || y < pos)
        return seg[node];
    if (x == y)
        return seg[node] = val;
    ll mid = (x + y) >> 1;
    return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
    if (y < lo || hi < x)
        return 0;
    if (lo <= x && y <= hi)
        return seg[node];
    ll mid = (x + y) >> 1;
    return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
		cin >> x;
        update(i, x, 1, 1, n);
    }
    for (int i = 0; i < m + k; i++) {
		cin >> x >> y >> z;
        if (x == 1)
            update(y, z, 1, 1, n);
        else
			cout << query(y, z, 1, 1, n) << "\n";
    }
    return 0;
}
