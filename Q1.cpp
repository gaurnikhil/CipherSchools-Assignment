#include <bits/stdc++.h>

using namespace std;

int findMissing(int n, vector<int> &arr){
    if(n <= 1){
        return -1;
    }
    
    for(int i=0; i<n; i++){
        while(arr[i] < n && arr[i] != i){
            swap(arr[i], arr[arr[i]]);
        }
    }
    
    for(int i=0; i<n; i++){
        if(i != arr[i]){
            return i;
        }
    }
    
    return -1;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans = findMissing(n, arr);
    
    cout<<ans;
}