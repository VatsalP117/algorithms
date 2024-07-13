//to find farthest distance of each node to any node
//property of diamater : The maximum distance of any node in the tree will be the maximum distance of that point from one of the end point of the Diameter.
//so first find both endpoints and then do bfs from both

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
int maxi;
int endpoint;

void dfs(int node,int dist,int parent){
    if(dist>maxi){
        maxi = dist;
        endpoint = node;
    }
    for(int adjNode:adj[node]){
        if(adjNode==parent) continue;
        dfs(adjNode,dist+1,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //pick random node 1 and find first endpoint of diamater
    maxi = 0;
    endpoint = 0;
    dfs(1,0,0);
    int a = endpoint;//first endpoint of diamater
    maxi = 0;
    endpoint = 0;
    dfs(a,0,0);
    int b = endpoint;
    //now do bfs from a and b
    vector<int> dist1(n+1,INT_MAX);
    vector<int> dist2(n+1,INT_MAX);
    queue<pair<int,int>> q;
    q.push({a,0});
    dist1[a] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(dis>dist1[node]) continue;
        for(int adjNode:adj[node]){
            if(1+dis<dist1[adjNode]){
                dist1[adjNode] = 1+dis;
                q.push({adjNode,1+dis});
            }
        }
    }
    dist2[b] = 0;
    q.push({b,0});
    while(!q.empty()){
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(dis>dist2[node]) continue;
        for(int adjNode:adj[node]){
            if(1+dis<dist2[adjNode]){
                dist2[adjNode] = 1+dis;
                q.push({adjNode,1+dis});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist1[i]==INT_MAX && dist2[i]==INT_MAX) cout<<0<<" ";
        else if(dist1[i]==INT_MAX) cout<<dist2[i]<<" ";
        else if(dist2[i]==INT_MAX) cout<<dist1[i]<<" ";
        
        else cout<<max(dist1[i],dist2[i])<<" ";
    }
    cout<<endl;
    return 0;

}