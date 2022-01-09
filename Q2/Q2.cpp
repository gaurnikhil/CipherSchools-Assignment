#include <bits/stdc++.h>

using namespace std;

//the function which will give us the closest sum to our target.
//the algorithm goes as follows
int findClosestSum(int n, int target, vector<int> &arr){
    //if the array is empty then return INT_MAX;
    if(n == 0){
        return INT_MAX;
    }
    
    //the midDiff variable will store the least difference from the target we could achieve so far.
    //initialize it as INT_MAX so that we could start with maximum and can get the possible smaller differences
    int minDiff = INT_MAX;
    
    //the ans variable store the closest sum to our target
    int ans = -1;
    
    //sort the vector
    sort(arr.begin(), arr.end());
    
    //iterate the array from first number to the second last number
    for(int i=1; i<n-1; i++){
        
        //place left pointer to one left of the current index. (left tends to move backwards)
        //place right pointer to one right of the current index. (right tends to move forward)
        
        int left = i-1;
        int right = i+1;
        
        //now iterate untill one of the pointers go beyond the limits.
        //i.e left
        while(left >= 0 && right < n){
            
            //the current sum of three elements
            int sum = arr[left] + arr[i] + arr[right];
            
            //the current difference from the target
            int diff = abs(target - sum);
            
            //if the current difference is lesser than the minimum difference we have seen so far then 
            //store the diff to the minDiff and the current sum as ans
            if(diff < minDiff){
                minDiff = diff;
                ans = sum;
            }
            
            //now in tend to move forward to our desired target we would move our left and right pointers as per
            //the requirement
            
            //if the sum is smaller than the target then  move the right pointer (increase the sum).
            if(sum < target){
                right++;
            }
            //if the sum is greater than the target then  move the left pointer (decrease the sum).
            else if(sum > target){
                left--;
            }
            //if the sum == target (diff ==0) then this is the closest we can get to the targer then return the sum as answer.
            else{
                return ans;
            }
        }
    }
    
    //return the final answer
    return ans;
}

int main() {
    int n;
    int target;
    cin>>n>>target;
    
    vector<int> arr(n);
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans = findClosestSum(n, target, arr);
    
    cout<<ans;
}