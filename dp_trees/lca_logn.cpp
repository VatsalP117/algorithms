//to answer queries of type find node k levels above u
//for each node store up(u,2^i)

#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<vector<int>> adj;
vector<int> tin, tout;
int up[200010][20];
int timer;

void binary_lifting(int node,int parent){
    tin[node] = ++timer;
    up[node][0] = parent;
    for(int i=1;i<20;i++){
        if(up[node][i-1]!=-1){
            up[node][i] = up[up[node][i-1]][i-1];
        }
        else up[node][i] = -1;
    }
    for(int child:adj[node]){
        if(child==parent) continue;
        binary_lifting(child,node);
    }
    tout[node] = ++timer;
}

bool is_ancestor(int u,int v){
    if(tin[u]<=tin[v] && tout[u]>=tout[v]){
        return true;
    }
    return false;
}

int lca(int u,int v){
    if(is_ancestor(u,v)){
        return u;
    }
    if(is_ancestor(v,u)){
        return v;
    }
    
    for(int i=19;i>=0;i--){
        if(up[u][i]!=-1 && !is_ancestor(up[u][i],v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}
void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    adj.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    memset(up,-1,sizeof(up));
    binary_lifting(1,-1);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}
int main(){
    solve();
    return 0;
}