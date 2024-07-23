//https://leetcode.com/problems/the-number-of-good-subsets/description/

class Solution {
public:
    //handle 1's separaely since it doesnt have any prime factors and we can make it join any good subset and it will still remain good
    vector<vector<int>> prime_factors;
    vector<int> freq;
    const int MOD = 1e9 + 7;
    unordered_map<int,unordered_map<int,long long>> dp;
    long long solve(int val, int mask) {
        if (val > 30) {
            return mask>0;
        }
        if(dp[val].count(mask)) return dp[val][mask];
        long long notTake = solve(val + 1, mask);
        long long take = 0;
        
        if (val > 1 && freq[val] > 0) {
            bool canTake = true;
            int new_mask = mask;
            for (int p : prime_factors[val]) {
                if (new_mask & (1 << p)) {
                    canTake = false;
                    break;
                }
                new_mask |= (1 << p);
            }
            if (canTake) {
                take = solve(val + 1, new_mask);
                take = (take * freq[val]) % MOD;
            }
        }
        
        return dp[val][mask]= (notTake + take) % MOD;
    }
    
    int numberOfGoodSubsets(vector<int>& nums) {
        prime_factors.resize(31);
        freq.resize(31, 0);
        for (int num : nums) freq[num]++;
        dp.clear();
        for (int j = 2; j <= 30; j++) {
            int num = j;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    while (num % i == 0) {
                        num /= i;
                        prime_factors[j].push_back(i);
                    }
                }
            }
            if (num > 1) prime_factors[j].push_back(num);
        }
        
        long long result = solve(2, 0);  // Subtract 1 to exclude the empty subset
        
        // Handle 1s : 2 options for every 1, either join this subset or dont
        for (int i = 0; i < freq[1]; i++) {
            result = (result * 2) % MOD;
        }
        
        return result;
    }
};
