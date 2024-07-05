//its nothing new, just using our hasher function for pattern matching
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//we making struct since it might be useful when have multiple strings to comapre

struct hasher{
    int sz;
    ll p,mod;
    vector<ll> fHash;
    vector<ll> pk;
    void init(string s,ll _p,ll _mod){
        p = _p;
        mod = _mod;
        sz = s.size();
        fHash.resize(sz);
        pk.resize(sz);
        fHash[0] = s[0] - 'a' + 1;
        pk[0] = 1;
        for(int i=1;i<sz;i++){
            fHash[i] = (fHash[i-1]*p + (s[i]-'a'+1));
            pk[i] = (pk[i-1]*p)%mod;
        }
    }

    ll getfHash(int l,int r){
        //hash for s[l..r]
        if(l==0) return fHash[r];
        ll k = (r-l+1);//size of substring
        return ((fHash[r] - fHash[l-1]*pk[k])%mod + mod)%mod;
        //return ((fHash[r] - fHash[l-1]*(p^k))%mod + mod)%mod;
        //yaha pe this p^k can be calculated quickly using binary power exponentiation which will make our function O(logN)
        //buts lets make it even quicker by caching p^k values in advance
    }
};

int main(){
    string text,pattern;
    cin>>text>>pattern;
    int n = text.size();
    int m = pattern.size();
    hasher phash;
    hasher thash;
    phash.init(pattern,31,1e9+7);
    thash.init(text,31,1e9+7);
    int h = phash.getfHash(0,m-1);//hash of complete pattern string
    for(int i=0;i<n-m+1;i++){
        if(thash.getfHash(i,i+m-1)==h){
            cout<<"Match found at index "<<i<<endl;
        }
    }
    return 0;
}
