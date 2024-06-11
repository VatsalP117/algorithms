//this is a hard problem for bitset
//bitset is used for various optimisations like subset sum, knapsack etc

//question is leetcode 3181
//https://leetcode.com/problems/maximum-total-reward-using-operations-ii/

class Solution {
public:

    int maxTotalReward(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        const int N = (int)1e5; //max sum possible
        bitset<N> dp, mask;
        int j = 0;
        //dp stores all sums which are possible till now
        dp[0] = 1; //we can make sum 0 by default
        for(int i=0;i<n;i++){
            //make all feasible values updated by nums[i]
            //so basically left shift all by nums[i]
            //but saare sum ko shift karke feasible nahi kar sakte dost
            //only those sums which are currently < nums[i]
            //so baaki bits ko mask se and karke 0 kardo easy
            while(j<arr[i]){
                mask[j] = 1;
                j++;
            }
            dp = dp | ((dp & mask) << arr[i]);
        }
        //now tell the biggest sum possible isme se iterate maarke
        for(int i=N-1;i>=0;i--){
            if(dp[i]==1){
                return i;
            }
        }
        return 0;
    }
};