//to find farthest distance of each node to any node
//property of diamater : The maximum distance of any node in the tree will be the maximum distance of that point from one of the end point of the Diameter.
//so first find both endpoints and then do bfs from both

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>> adj;
vector<int> in; //max distance to a leaf node inside the subtree
vector<int> out; //max distance to a leaf node outside the subtree

//calculates in array
void dfs1(int node,int parent){
    in[node] = 0LL;
    for(int adjNode:adj[node]){
        if(adjNode==parent) continue;
        dfs1(adjNode,node);
        in[node] = max(in[node],1+in[adjNode]);
    }
}

void dfs2(int node,int parent){
    int mx1 = -1;
    int mx2 = -1;
    for(int child:adj[node]){
        if(child==parent) continue;
        if(in[child]>=mx1){
            mx2 = mx1;
            mx1 = in[child];
        }
        else if(in[child]>=mx2) mx2 = in[child];
    }
    for(int child:adj[node]){
        if(child==parent) continue;
        int use = mx1;
        if(in[child]==use) use = mx2;
        out[child] = max(1LL+out[node],2LL+use);
        dfs2(child,node);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    adj.resize(n+1);
    in.resize(n+1,0);
    out.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //we can root our tree at any node, lets root it at 1
    //lets first calculate in array, in = basically stores depth of each subtree
    dfs1(1,0);
    //now calculate out for each node
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<max(in[i],out[i])<<" ";
    }
    return 0;

}