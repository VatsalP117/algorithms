//https://leetcode.com/problems/count-the-number-of-good-partitions/description/

class Solution {
public:
    int dp[100010];
    unordered_map<int,int> last_idx;
    const int MOD = 1e9 + 7;
    int solve(int ind,int n,vector<int> &nums){
        if(ind>=n){
            return 1;
        }
        if(dp[ind]!=-1) return dp[ind];
        //if we include an element, we must inlcude all occurences of this element
        //therefore this subarray must extend till the last index of element included in it
        int i = ind;
        int j = last_idx[nums[i]];
        while(i<j){
            j = max(j,last_idx[nums[i]]);
            i++;
        }
        //so now we know valid subarray starting from here
        //we can either start a new segment from this index or join previous one
        //(can join previous one only if ind>0 else who to join)
        int options = ind>0 ? 2 : 1;
        long long ans = 1LL * options * solve(j+1,n,nums);
        return dp[ind] = ans%MOD;

    }
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        last_idx.clear();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            last_idx[nums[i]] = i;
        }
        return solve(0,n,nums);
    }
};
