#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> adj;
vector<int> in;  // sum of distances to all nodes in my subtree
vector<int> out; // sum of distances to all nodes outside my subtree
vector<int> sub; // size of subtree of each node

void dfs1(int node, int parent) {
    sub[node] = 1;
    in[node] = 0;
    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs1(child, node);
        sub[node] += sub[child];
        in[node] += in[child] + sub[child];
    }
}

void dfs2(int node, int parent) {
    for (int child : adj[node]) {
        if (child == parent) continue;
        out[child] = (out[node] + in[node] - in[child] - sub[child]) + (n - sub[child]);
        dfs2(child, node);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    adj.resize(n + 1);
    in.resize(n + 1, 0);
    out.resize(n + 1, 0);
    sub.resize(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs1(1, 0);  // Calculate in[] and sub[]
    dfs2(1, 0);  // Calculate out[]
    
    for (int i = 1; i <= n; i++) {
        cout << in[i] + out[i] << " ";
    }
    
    return 0;
}