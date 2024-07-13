#include <bits/stdc++.h>
// Given a tree with n
//  nodes are multiple ways to find a diameter. Here is one of the simplest ways:

// Run a DFS from any node p
// . Let a
//  be a node whose distance from node p
//  is maximized. Run another DFS from node a
// . Let b
//  be a node whose distance from node a
//  is maximized. a→b
//  is a diameter.
using namespace std;
int maxi;
int start;
void dfs(int node, int par, int dis, vector < vector < int >> & adj) {
    if (dis > maxi) {
        maxi = dis;
        start = node;
        //cout<<dis<<endl;
    }
    for (int adjNode: adj[node]) {
        if (adjNode != par) {
            dfs(adjNode, node, dis + 1, adj);
        }
    }
}
int main() {
    // your code goes here
    int n;
    cin >> n;
    vector < vector < int >> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxi = 0;
    start = -1;
    dfs(1, -1, 0, adj);
    //now start dfs from start node 
    dfs(start, -1, 0, adj);
    cout << maxi << endl;
    //pick a random node, say 0 and go to the farthest node from that
    return 0;
}