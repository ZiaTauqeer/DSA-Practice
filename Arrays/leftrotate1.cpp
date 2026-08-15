#include<bits/stdc++.h>
using namespace std;

void leftrotate(int n,int arr[]){
    int temp = arr[0];
    for (int i=1;i<n;i++){
        arr[i-1]=arr[i];//shift elements to left
    }
    arr[n-1]=temp;
}

int main(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"Enter array elements"<<endl;
        cin>>arr[i];
        cout<<"The og array is: "<<arr[i]<<" "<<endl;
    }
    leftrotate(n, arr);
    cout << "\nThe array after one left rotation is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "<<endl;
    }
    return 0;
}