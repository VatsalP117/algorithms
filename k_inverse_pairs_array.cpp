class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        //dp[i][j] = i length arrays having exactly j inversions
        //base case : for any length i, for there to be 0 inversions there is only 1 way i.e the sorted order
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        //now lets come to our recurrence
        //say i want to extend the i-1 length array to i length now, so basically i will put the element with value "i" somewhere
        //if i put it after last, i wont create any additonal inversions
        //if i put it just before last, i will create 1 extra inversion with the last inversion ( since i am biggest)
        //before that i will create 2 inversions
        //max will be i put it before first and i will create i-1 (prev length) new inversions
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                //x = number of extra inversions i will create
                // for(int x=0;x<i;x++){
                //     if(j-x>=0)dp[i][j] += dp[i-1][j-x];
                // }
                //to optimise this : dp[i][j] = d[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2] ... +dp[i-1][max(0,j-i+1)]
                //dp[i-1][j] ke alava to sab dp[i][j-1] mai bhi hoga hi na?
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
                //vo last dp[i-1][max(0,j-i+1)] wale term ka setting karne next step, write recurrence and see kaise aaya its easy
                if(j>=i){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};
