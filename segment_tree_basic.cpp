#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define int long long
struct node{
	int sum;
	node(){
		sum = 0;
	}
};
node merge(node a,node b){
	node ans;
	ans.sum = a.sum + b.sum;
	return ans;
}
//200200 is the size of array, always create this tree array of size 4n or more
node t[4*200200];
void build(int id,int l,int r){
	//id is node ka id
	//(l,r) give the range in the array for which this node is responsible for
	if(l==r){
		//leaf node
		t[id].sum = 0; // set value according to question
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
		t[id].sum += val; //could be equal to instead of add in other questions
		return;
	}
	int mid = (l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	t[id] = merge(t[2*id],t[2*id+1]);
}
 
node query(int id,int l,int r,int lq,int rq){
	//what does this mean?
	//it says go to this node with this id, which is responsible for range l,r
	//and get the sum(in this case) for whichever part intersects with given query range (lq,rq)
 
	if(l>rq || lq>r){
		//no intersection
		return node();
	}
	if(lq<=l && r<=rq) return t[id];
	int mid = (l+r)/2;
	return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
 
 
