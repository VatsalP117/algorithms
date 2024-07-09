#include <bits/stdc++.h>
using namespace std;
struct node{
    node *child[2];
    int cnt;
    node(){
        child[0] = NULL;
        child[1] = NULL;
        cnt = 0;
    }
};

struct trie{
    node *root;//root node
    int LN;//number of bits of numbers we will be be inserting
    trie(int x = 32){
        root = new node();
        LN = x;
    }

    void insert(int n){
        node *curr = root;
        for(int i=LN-1;i>=0;i--){
            curr->cnt++;
            int x = (n&(1<<i)) ? 1 : 0;
            if(curr->child[x]==NULL){
                curr->child[x] = new node();
            }
            curr = curr->child[x];
        }
        curr->cnt++;
    }
    //for delete same code, just change cnt++ to cnt--
     void deleteNode(int n){
        node *curr = root;
        for(int i=LN-1;i>=0;i--){
            curr->cnt--;
            int x = (n&(1<<i)) ? 1 : 0;
            if(curr->child[x]==NULL){
                curr->child[x] = new node();
            }
            curr = curr->child[x];
        }
        curr->cnt--;
    }


};
int main(){


    return 0;
}