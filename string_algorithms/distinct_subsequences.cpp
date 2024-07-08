class Solution {
public:
    const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> occ[26];
        for(int i=0;i<n;i++){
            occ[s[i]-'a'].push_back(i);
        }
        vector<long> dp(n+1,0);
        //indexes shifted by 1
        dp[0] = 1;//blank string
        for(int i=1;i<=n;i++){
            int ch = s[i-1]-'a';
            dp[i] = (dp[i] + dp[i-1]) % MOD;
            dp[i] = (dp[i] + dp[i-1]) % MOD;
            if(occ[ch].size()>1){
                auto it = lower_bound(occ[ch].begin(),occ[ch].end(),i-1);
                if(it!=occ[ch].begin()) {
                    it--;
                    dp[i] = (dp[i] - dp[*it] + MOD) % MOD; // Adjust subtraction to prevent negative values
                }
            }
        }
        int result = (dp[n] - 1 + MOD) % MOD;
        return result;
    }
};
