#include <bits/stdc++.h>
using namespace std;

int lis(int n,vector<int> &arr){
    vector<int> lis;//this essentially stores the min possible last value for each length subsequence possible
    //the indexes (sort of) corresponsed to length and value to last value
    //lis will be in sorted order 
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            //then we can extend even the highest length lis since uska last value < our value
            lis.push_back(arr[i]);
        }
        else{
            //find the biggest length that we can extend
            //that is the biggest last value (and hence the biggest length) which is < arr[i]
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
        }
    }
    //the elements inside the lis are not the lis itself tho, we just have a paretial solution as length of lis but not lis itself
    return lis.size();
}
//but how do we print the LIS itself in nlogn time?
void printLis(int n,vector<int> &arr){
    vector<int> lis;//this essentially stores the min possible last value for each length subsequence possible
    //the indexes (sort of) corresponsed to length and value to last value
    //lis will be in sorted order 
    vector<int> insertedAt(n);//stores ye elemnt konsi size ke subsequence ka last element ban paya
    //the level at which it was inserted at
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            //then we can extend even the highest length lis since uska last value < our value
            lis.push_back(arr[i]);
            insertedAt[i] = lis.size();
        }
        else{
            //find the biggest length that we can extend
            //that is the biggest last value (and hence the biggest length) which is < arr[i]
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            insertedAt[i] = it-lis.begin()+1;//+1 for size varna konse index pe gya vo batayega
        }
    }
    vector<int> final_lis;
    //the elements inside the lis are not the lis itself tho, we just have a paretial solution as length of lis but not lis itself
    int curLen = lis.size();
    for(int i=n-1;i>=0;i--){
        if(insertedAt[i]==curLen){
            final_lis.push_back(arr[i]);
            curLen--;
        }
    }
    reverse(final_lis.begin(),final_lis.end());
    for(int v:final_lis) cout<<v<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lis(n,arr)<<endl;
    printLis(n,arr);
    return 0;
}