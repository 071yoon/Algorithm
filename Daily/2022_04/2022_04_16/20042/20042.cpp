#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int parent[500000];
int ans;

int finder(int node)
{
    if (parent[node] == node) 
		return (node);
    else 
		return (parent[node] = finder(parent[node]));
}

bool union_node(int u, int v)
{
    u = finder(u);
    v = finder(v);
    if (u == v) return true;
    else {
        parent[u] = v;
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (union_node(u, v)) {
            ans = i;
            break;
        }
    }

    if (ans == 0) 
		cout << 0 << "\n";
    else 
		cout << ans << "\n";

}