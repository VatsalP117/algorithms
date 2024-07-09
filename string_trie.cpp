//helps process sufix and prefixes of strings in efficient manner
#include <bits/stdc++.h>
using namespace std;

struct node{
    node* child[26];
    int prefix; //proper prefixes yaha se passing (like count)
    vector<string> wend;
    node(){
        prefix = 0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};


struct trie{
    node* root;
    trie(){
        root = new node();
    }

    void insert(string &s){
        node* curr = root;
        for(int i=0;i<s.size();i++){
            curr->prefix++;
            int x = s[i]-'a';
            if(curr->child[x]==NULL){
                curr->child[x] = new node();
            }
            curr = curr->child[x];
        }
        //curr->prefix++; do this we dont need proper prefix, entire string == prefix also works
        curr->wend.push_back(s);
    }

    void deleteNode(string &s){
        node* curr = root;
        for(int i=0;i<s.size();i++){
            curr->prefix--;
            int x = s[i]-'a';
            if(curr->child[x]==NULL){
                curr->child[x] = new node();
            }
            curr = curr->child[x];
        }
        curr->wend.pop_back();
    }
};