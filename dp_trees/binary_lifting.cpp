//to answer queries of type find node k levels above u
//for each node store up(u,2^i)

#include <bits/stdc++.h>
using namespace std;


int n,q;
vector<vector<int>> adj;
int up[200001][20];//up[u][i] = node 2^i levels up from u

void binary_lifting(int node,int parent){
    up[node][0] = parent;//1 level above
    for(int i=1;i<20;i++){
        //to go 2^x levels up, go 2^(x-1) levels up and waha se aur 2^x-1 levels up
        if(up[node][i-1]!=-1){
            up[node][i] = up[up[node][i-1]][i-1];
        }
        else up[node][i] = -1;
    }
    for(int child:adj[node]){
        if(child==parent) continue;
        binary_lifting(child,node);
    }
}

int ans_query(int node,int k){
    //k = jumps needed
    if(node==-1 || k==0){
        return node;
    }
    //evaluate the binary number k
    for(int i=19;i>=0;i--){
        if((k & (1<<i))!=0){
            //unset kardo aage ke liye ye bit using xor or subtraction
            return ans_query(up[node][i],k-(1<<i));
        }
    }
}
void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    //1 is root node
    adj.resize(n+1);
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        //a is the parent of ith node
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    binary_lifting(1,-1);
    for(int i=0;i<q;i++){
        int x,k;
        cin>>x>>k;
        cout<<ans_query(x,k)<<endl;
    }
}
int main(){
    solve();
    return 0;
}