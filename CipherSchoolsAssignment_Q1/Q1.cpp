#include <bits/stdc++.h>

using namespace std;

//declaring the findMissing function which will give us the missing number from the array

int findMissing(int n, vector<int> &arr){
    
    //if the list is empty then return -1
    if(n == 0){
        return -1;
    }
    
    //so the concept is simple: since all the numbers are in range of [0,n], means there exists a index for
    //same as each number in our vector except one number (the missing one).
    
    //so to use it we make the following operations:
    
    for(int i=0; i<n; i++){

        //swap the numbers untill the current number is not same as the current index or the current number is
        //greater than or equals to n (maximum index is n-1).
        while(arr[i] < n && arr[i] != i){

            //place the current number at its right place
            swap(arr[i], arr[arr[i]]);
        }
    }
    
    //now after placing all the numbers at their rightful places reiterate the array, now if the current number
    //is not equal to the corresponding index then this index is our missing number.
    for(int i=0; i<n; i++){
        if(i != arr[i]){
            return i;
        }
    }
    
    //if all the numbers has their corresponding indices then the only number possible to miss is the number "n".
    return n;
}

int main() {
    //number of elements in the array
    int n;
    cin>>n;
    
    //vector of numbers
    vector<int> arr(n);
    
    //taking the input for the numbers
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    //initializing the ans variable
    int ans; 
    
    //calling the findMissing function to do the required operation
    ans = findMissing(n, arr);
    
    if(ans != -1){
        cout<<ans;
    }
    else{
        cout<<"invalid input";
    }
}