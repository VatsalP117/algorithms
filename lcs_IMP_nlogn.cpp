//when one string has distinct characters only, you can find lcs in nlogn time by converting to lis
//ques : https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
       int n = arr.size();
       map<int,int> m;
       for(int i=0;i<target.size();i++){
         m[target[i]] = i;
       } 
       vector<int> a;
       for(int i=0;i<n;i++){
            if(m.find(arr[i])!=m.end()){
                a.push_back(m[arr[i]]);
            }
       }
       //now find lis of a
       vector<int> lis;
       for(int i=0;i<a.size();i++){
            if(lis.empty() || lis.back()<a[i]){
                lis.push_back(a[i]);
            }
            else{
                auto it = lower_bound(lis.begin(),lis.end(),a[i]);
                *it = a[i];
            }
       }
       return target.size() - lis.size();
    }
};