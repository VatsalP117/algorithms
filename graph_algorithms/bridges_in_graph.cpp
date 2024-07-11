
//best video to understand this : https://www.youtube.com/watch?v=R_bFeK5MR6I
//a bridge in a graph is an edge such that if we remove it, the graph breaks into multiple components
//given a graph, we have to return all bridges in it
// Main logic is say there is an edge between a and b to if we find a find a path from b to a without using this edge,
// then this edge cannot be a bridge since vo dusre raaste se to dono connected hi rahenge 
// so naively you can remove every edge, and do dfs from one vertex of the node and if we reach the other its not a bridge
// also all edges involved in the same cycle cannot be bridge

// so if a(parent in dfs) calls b and to check for bridge edge between a&b, you can where all b can reach 
// and if b can reach someone before a (some ancestor of a who came before it in dfs) then not a bridge
// but how to check every node reachable from b in efficient way?
// give time when we find a node in dfs to every node (smaller the number, utna pehle mila vo)
// and for every node b can reach, store minimum value of this time for all its neighbours i.e sabse piche wale konse ancestor tak ja sakta hai 
// if that node is ancestor of a to its not a bridge easy 

class Solution {
public:
    void dfs(int node,int parent,int &count,vector<int> &disc,vector<int> &low,vector<int> &vis,vector<vector<int>> &adj,vector<vector<int>> &bridges){
        disc[node] = low[node] = count;
        vis[node] = 1;
        for(int adjNode : adj[node]){
            if(adjNode==parent) continue;
            if(vis[adjNode]==1){
                low[node] = min(low[node],low[adjNode]);
            }
            else{
                count++;//give it a new discovery time for dfs
                dfs(adjNode,node,count,disc,low,vis,adj,bridges);
                if(low[adjNode]>disc[node]){
                    //ye bichara mere tak nahi pahoch payega kabhi so this is bridge
                    bridges.push_back({node,adjNode});
                }
                low[node] = min(low[node],low[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<int> disc(n);//will store discovery time for all nodes
        vector<int> low(n);//will store ki sabse piche konse bande tak ja raha h ye i.e reachble node with lowest disc value
        vector<int> vis(n,0);
        int count = 0;//ye discovery time ko value dene bas banaya hai
        dfs(0,-1,count,disc,low,vis,adj,bridges);
        return bridges;
    }
};