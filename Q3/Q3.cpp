#include <bits/stdc++.h>

using namespace std;

//the dunction houseRobber will give us the maximum amount he can rob given the condition
int houseRobber(int n, vector<int> &arr){
    //if there are no house then return 0.
    if(n == 0)
        return 0;
        
    //if there is only one house then return the value of this house
    if(n == 1)
        return arr[0];
      
    //now we will solve this problem using dynamic programming concept
    //for that we will create a dp vector for storing the answers of each step
    vector<int> dp(n,0);
      
     //for 1 house the answer will be the value of that house only  
    dp[0] = arr[0];
    
    //for 2 houses the answer will be the maximum of both houses
    dp[1] = max(arr[0], arr[1]);
        
    for(int i=2; i<n; i++){
        
        //now the robber has two options at every step
        //Either he rob the current house of not
        
        //if he rob the current house then he has the amount he has robbed until the house before the last one
        //plus the value of the current house
        int rob = arr[i] + dp[i-2];
        
        //if he do not rob the house then he will continue with the amount he has before this house.
        int notRob = dp[i-1];
        
        //now he will move forward with the maximum he gets after these two scenarios
        dp[i] = max(rob, notRob);
    }
        
    //return the amount he accomodated untill the last house (last house included).
    return dp[n-1];
}

int main() {
    int n;
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans = houseRobber(n, arr);
    
    cout<<ans;
}