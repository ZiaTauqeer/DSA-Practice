#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int mini=i;
        for (int j=i; j<= n-1; j++){
            if (arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp = arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
}
int main(){
    int n;
    cout<<"enter number of values in array"<<endl;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"Enter element value"<<endl;
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}