//https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
class Solution {
public:
    #define ll long long
    const int MOD = 1e9 + 7;
    int nCr[1001][1001];
    //use formula : n C r = n-1 C r + n-1 C r-1
    //number of combines = left subtree ways * right subtree ways * x+y C x
    //where x = number of elements in left subtree and y = num elements in right subtree
    ll ways(vector<int> &a){
        //first element of this must be the root : check for rest all elements > or <
        int sz = a.size();
        if(sz<=2) return 1;
        vector<int> left, right;
        int root = a[0];
        for(int i=1;i<sz;i++){
            if(a[i]<=root){
                left.push_back(a[i]);
            }
            else right.push_back(a[i]);
        }
        int l = left.size();
        int r = right.size();
        return (1LL * ways(left) * ways(right) % MOD * nCr[l+r][l]) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++){
            nCr[i][0] = nCr[i][i] = 1;
            for(int j=1;j<i;j++){
                nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;
            }
        }
        return ways(nums)-1;
    }
};
