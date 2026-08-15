#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array "<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n;i++){
        cout<<"Enter array element:"<<endl;
        cin>>arr[i];
    }
    int largest = arr[0];
    for (int i=0;i<n;i++){
        if (arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<"The largest element is:"<<largest<<endl;

}