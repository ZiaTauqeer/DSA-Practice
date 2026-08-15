#include <bits/stdc++.h>
using namespace std;

void reversearr(int i,int arr[] ,int n){
    if (i >=n/2){ //signifies half way of the array
        return;
    }
    swap(arr[i],arr[n-1-i]); //swap first and last position
    reversearr(i+1,arr,n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n; i++){
        cin>>arr[i];
    }
    reversearr(0,arr,n);
    for (int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}