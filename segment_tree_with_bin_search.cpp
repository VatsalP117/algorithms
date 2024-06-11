//problem cses hotel queries
//inbuilt binary search query
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define int long long
struct node{
	int max_val;
	node(){
		max_val = 0;
	}
};
node merge(node a,node b){
	node ans;
	ans.max_val = max(a.max_val,b.max_val);
	return ans;
}
//200200 is the size of array, always create this tree array of size 4n or more
node t[4*200200];
vector<int> arr(200200);
void build(int id,int l,int r){
	//id is node ka id
	//(l,r) give the range in the array for which this node is responsible for
	if(l==r){
		//leaf node
		t[id].max_val = arr[l]; // set value according to question
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);//build left subtree
	build(2*id+1,mid+1,r);//build right subtree
	t[id] = merge(t[2*id],t[2*id+1]);
}
 
void update(int id,int l,int r,int pos,int val){
	//what does this mean?
	//it says go to node with this id, which is responsible for range l to r
	//and then update the index pos(if it is in its range) with new value = val
	if(pos<l || pos>r){
		return;
	}
	if(l==r){
		//means this is leaf
		//and first case ensure pos lies in our range (l,r)
		//means pos == l == r
		t[id].max_val -= val; //could be equal to instead of add in other questions
		return;
	}
	int mid = (l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	t[id] = merge(t[2*id],t[2*id+1]);
}
 
int query(int id,int l,int r,int req){
	//what does this mean?
	//it says go to this node with this id, which is responsible for range l,r
	//and get the sum(in this case) for whichever part intersects with given query range (lq,rq)
 
	if(t[id].max_val<req){
		return -1;
	}
	if(l==r){
		return l;
	}
	int mid = (l+r)/2;
	if(t[2*id].max_val>=req){
		return query(2*id,l,mid,req);
	}
	else return query(2*id+1,mid+1,r,req);
 
 
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	build(1,0,n-1);
	for(int i=0;i<m;i++){
		int req;
		cin>>req;
		int idx = query(1,0,n-1,req);
		cout<<idx+1<<" "; //converting to 1 based index
		if(idx!=-1){
			update(1,0,n-1,idx,req);
		}
		
	}
}